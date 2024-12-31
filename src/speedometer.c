#include <avr/io.h>
#include <avr/power.h>
#include <avr/sleep.h>

#include "../inc/led.h"
#include "../inc/oled.h"
#include "../inc/sensor.h"
#include "../inc/time.h"

#define SCREEN_WIDTH	(128)	// OLED display width in pixels
#define SCREEN_HEIGHT 	(64)	// OLED display height in pixels
#define SCREEN_ADDRESS 	(0x3D)	// TWI Address

void setup(void);
void loop(void);
int main(void);

static struct SSD1306 oled;
static u8 oled_buffer[OLED_BUFFER_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT)];

/* Initialize all hardware modules and software variables */
void setup(void)
{
	LED_DDR |= _BV(LED_PIN);

	ADCSRA &= ~_BV(ADEN);	// Disable ADC
	power_all_disable();	// Remove power from all unused devices

	set_sleep_mode(SLEEP_MODE_IDLE);	// Set sleep mode used to idle

	// Initialize hardware and software
	oled_init(
		&oled,
		SCREEN_ADDRESS,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		oled_buffer
	);
	sensor_init();
	millis_init();

	oled_test(&oled);
}

/* Update OLED display with measured information every second */
void loop(void)
{
	// Ignore timer 0 interrupts to set millis, only wake up on timer 3
	if (millis() % 1000 == 0) {
		// power_twi_enable();
		// oled_update();
		// power_twi_disable();
	}

	sleep_mode();	// Enter low-power mode when waiting
}

int main(void)
{
	setup();

	for (;;) {
		loop();
	}
}

