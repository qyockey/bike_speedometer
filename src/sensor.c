#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdbool.h>

#include "../inc/num_types.h"
#include "../inc/sensor.h"
#include "../inc/time.h"

// Sensor on port D pin 2 (Arduino D0)
#define SENSOR_PIN		(PD2)
#define SENSOR_DDR 		(DDRD)
#define SENSOR_PORT		(PORTD)
#define SENSOR_INT		(INT2)
#define SENSOR_INT_VECTOR	(INT2_vect)
#define SENSOR_TRIGGER_LO	(ISC20)
#define SENSOR_TRIGGER_HI	(ISC21)

#define MILLIS_PER_SEC		(1000UL)
#define SECS_PER_HOUR		(3600UL)
#define MILLIS_PER_HOUR		(MILLIS_PER_SEC * SECS_PER_HOUR)
#define METERS_PER_KM		(1000UL)
#define WHEEL_DIAMETER		(0.66 / METERS_PER_KM) // km
#define WHEEL_CIRCUMFERENCE	(M_PI * WHEEL_DIAMETER) // km

#define SAMPLE_PULSES		(4)
#define SAMPLE_DISTANCE		((SAMPLE_PULSES - 1) * WHEEL_CIRCUMFERENCE)
#define SAMPLE_MIN_SEPARATION	(100) // ms
#define STOPPED_THRESHOLD	(5000) // ms

static volatile u32 timestamps[SAMPLE_PULSES];
static volatile u32 millis_elapsed;
static volatile u32 pulses;

static void timestamps_init(void);

/* Initialize timestamps */
static void timestamps_init(void)
{
        pulses = 0;

	for (u8 i = 0; i < SAMPLE_PULSES; ++i) {
		timestamps[i] = millis_elapsed;
	}
}

/* Initialize reed switch sensor falling edge interrupt on sensor pin */
void sensor_init(void)
{
	timestamps_init();

	cli();		// Disable interrupts during configuration

	UCSR1B = 0;	// Disable USART on sensor pin

	SENSOR_DDR &= ~_BV(SENSOR_PIN);	// Sensor pin input
	SENSOR_PORT |= _BV(SENSOR_PIN);	// Activate pullup resistor

	EICRA &= ~_BV(SENSOR_TRIGGER_LO);	// Trigger on falling edge
	EICRA |= _BV(SENSOR_TRIGGER_HI);

	EIMSK |= _BV(SENSOR_INT);		// Enable sensor interrupt

	sei();	// Re-enable interrupts
}

/* Calculate displayed values and write them to the OLED display */
void sensor_get_measurements(struct SensorMeasurements* measurements)
{
	const u32 millis_elapsed = millis();
	const u32 last_sample = timestamps[SAMPLE_PULSES - 1];
	const u32 sample_duration = last_sample - timestamps[0];
	const bool stopped = millis_elapsed - last_sample >= STOPPED_THRESHOLD;

	const f64 km_per_ms = sample_duration == 0.0 ? 0.0 :
			SAMPLE_DISTANCE / (f64) sample_duration;
	const f64 km_per_hour = km_per_ms * ((f64) MILLIS_PER_HOUR);

	measurements->velocity_sample = stopped ? 0.0 : km_per_hour;
	const f64 distance_traveled = pulses * WHEEL_CIRCUMFERENCE;
	measurements->distance_traveled = distance_traveled;
	measurements->velocity_average = distance_traveled / millis_elapsed *
			(f64) MILLIS_PER_HOUR;
}

/* Process sensor pulse */
ISR(SENSOR_INT_VECTOR)
{
	const u32 millis_elapsed = millis();
	const u32 delta = millis_elapsed - timestamps[SAMPLE_PULSES - 1];

	// Software debounce
	if (delta < SAMPLE_MIN_SEPARATION) {
		return;
	}

	if (delta >= STOPPED_THRESHOLD) {
		// Reset all timestamps after long pause
		for (u8 i = 0; i < SAMPLE_PULSES; ++i) {
			timestamps[i] = millis_elapsed;
		}
	} else {
		// Shift values over
		u8 i;
		for (i = 0; i < SAMPLE_PULSES - 1; ++i) {
			timestamps[i] = timestamps[i + 1];
		}
		timestamps[i] = millis_elapsed;
	}

	++pulses;
}

