#ifndef __STATUS_DISPLAY_H
#define __STATUS_DISPLAY_H

#include "sensor.h"
#include "ssd1306.h"

/* Update quantities displayed on OLED */
void ssd1306_update(
		struct SSD1306* oled,
		const struct SensorMeasurements* measurements
);

#endif // __STATUS_DISPLAY_H

