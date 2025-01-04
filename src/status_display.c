#include "../inc/status_display.h"
#include "../inc/sensor.h"
#include "../inc/ssd1306.h"
#include "../inc/time.h"

#define MILLIS_PER_SECOND  (1000)
#define SECONDS_PER_MINUTE (60)
#define MINUTES_PER_HOUR   (60)

static void f64_to_str_2p0(char s[3], f64 val);
static void f64_to_str_2p1(char s[5], f64 val);

static void u8_to_str(char* s, u8 val)
{
	s[0] = '0' + val / 10;
	s[1] = '0' + val % 10;

	return;
}

static void f64_to_str_2p0(char s[3], f64 val)
{

	u8_to_str(s, val);
	s[2] = '\0';

	return;
}

static void f64_to_str_2p1(char s[5], f64 val)
{
	u8 decimal = ((u8)(10 * val)) % 10;
	u8_to_str(s, val);
	s[2] = '.';
	s[3] = '0' + decimal;
	s[4] = '\0';

	return;
}

static void set_time_str(char s[6])
{
	const u32 millis_elapsed  = millis();
	const u32 seconds_elapsed = millis_elapsed / MILLIS_PER_SECOND;
	const u32 minutes_elapsed = seconds_elapsed / SECONDS_PER_MINUTE;
	const u32 hours_elapsed   = minutes_elapsed / SECONDS_PER_MINUTE;

	const u32 hours   = hours_elapsed;
	const u32 minutes = minutes_elapsed % MINUTES_PER_HOUR;
	const u32 seconds = seconds_elapsed % SECONDS_PER_MINUTE;

	u8 left;
	u8 right;

	if (hours_elapsed == 0) {
		left  = minutes;
		right = seconds;
	} else {
		left  = hours;
		right = minutes;
	}

	u8_to_str(s, left);
	s[2] = ':';
	u8_to_str(s + 3, right);
	s[5] = '\0';

	return;
}

/* Update quantities displayed on OLED */
void ssd1306_update(
		struct SSD1306* oled,
		const struct SensorMeasurements* measurements
)
{
	char velocity_sample_str[3];
	char velocity_average_str[3];
	char distance_traveled_str[5];
	char time_str[6];

	f64_to_str_2p0(velocity_sample_str, measurements->velocity_sample);
	f64_to_str_2p0(velocity_average_str, measurements->velocity_average);
	f64_to_str_2p1(distance_traveled_str, measurements->distance_traveled);
	set_time_str(time_str);

	ssd1306_set_cursor(oled, 0, 0);
	ssd1306_clear(oled);

	ssd1306_puts(oled, velocity_sample_str);
	ssd1306_puts(oled, " kph\n");

	ssd1306_puts(oled, velocity_average_str);
	ssd1306_puts(oled, " kph avg\n");

	ssd1306_puts(oled, distance_traveled_str);
	ssd1306_puts(oled, " km\n");

	ssd1306_puts(oled, time_str);
	ssd1306_putc(oled, '\n');

	ssd1306_display(oled);

	// #ifdef NO_PRETTY
	// 	oled.setCursor(0, 0);
	//
	// 	oled.print(velocity_sample);
	// 	oled.println(" kph");
	//
	// 	oled.print(velocity_average);
	// 	oled.println(" kph avg");
	//
	// 	oled.print(distance);
	// 	oled.println(" km");
	//
	// 	oled_print_padded(minutes);
	// 	oled.print(":");
	// 	oled_print_padded(seconds);
	// 	oled.println();
	//
	// 	oled.print(pulses);
	// 	oled.println(" pulses");
	//
	// #else
	// 	oled.setCursor(6, 8);
	// 	oled.setTextSize(3);
	// 	oled_print_padded((u8) velocity_sample);
	// 	oled.setTextSize(1);
	// 	oled.setCursor(7 * 6, 1 * 8);
	// 	oled.print("k");
	// 	oled.setCursor(7 * 6, 2 * 8 - 1);
	// 	oled.print("p");
	// 	oled.setCursor(7 * 6, 3 * 8);
	// 	oled.print("h");
	//
	// 	oled.setCursor(1 * 6, 5 * 8);
	// 	oled.setTextSize(2);
	// 	oled_print_padded((u8) velocity_average);
	// 	oled.setTextSize(1);
	// 	oled.print("kph");
	// 	oled.setCursor(5 * 6, 6 * 8);
	// 	oled.print("avg");
	//
	// 	oled.setCursor(10 * 6, 1 * 8 + 4);
	// 	oled.setTextSize(2);
	// 	oled_print_padded((u8) distance);
	// 	oled.print(".");
	// 	oled.print(((u8) (10 * distance)) % 10, DEC);
	// 	oled.setCursor(18 * 6, 2 * 8);
	// 	oled.setTextSize(1);
	// 	oled.print("km");
	//
	// 	oled.setCursor(10 * 6, 5 * 8);
	// 	oled.setTextSize(2);
	// 	oled_print_padded(minutes);
	// 	oled.print(":");
	// 	oled_print_padded(seconds);
	// #endif
	//
	// 	oled.display();

	return;
}

