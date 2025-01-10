#include <avr/io.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <util/delay.h>

#include "../inc/led.h"
#include "../inc/sensor.h"
#include "../inc/ssd1306.h"
#include "../inc/status_display.h"
#include "../inc/time.h"

#define SSD1306_TWI_ADDRESS (0x3D)
#define MILLIS_PER_SECOND   (1000)

void setup(void);
void loop(void);
int main(void);

static struct SSD1306 oled;

void ssd1306_test(void)
{
	// ssd1306_putc(&oled, 'A');
	// ssd1306_display(&oled);
	return;
}

/* Initialize all hardware modules and software variables */
void setup(void)
{
	LED_DDR |= _BV(LED_PIN);

	ADCSRA &= ~_BV(ADEN);            // Disable ADC
	power_all_disable();             // Remove power from all unused devices

	set_sleep_mode(SLEEP_MODE_IDLE); // Set sleep mode used to idle

	// Initialize hardware and software
	ssd1306_init(&oled, SSD1306_TWI_ADDRESS);
	sensor_init();
	millis_init();

	ssd1306_test();

	return;
}

/* Update OLED display with measured information every second */
void loop(void)
{
	static struct SensorMeasurements measurements;

	// Process measurements once a second
	if (millis() % MILLIS_PER_SECOND == 0) {
		LED_PORT ^= _BV(LED_PIN);
		sensor_get_measurements(&measurements);
		ssd1306_update(&oled, &measurements);
	}

	// Enter low-power mode when waiting
	// sleep_mode();

	return;
}

int main(void)
{
	setup();

	for (;;) {
		loop();
	}

	return 0;
}

