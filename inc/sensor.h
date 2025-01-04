#ifndef __SENSOR_H
#define __SENSOR_H

#include <avr/io.h>

#include "num_types.h"

struct SensorMeasurements {
	f64 velocity_sample;
	f64 velocity_average;
	f64 distance_traveled;
};

void sensor_init(void);
void sensor_get_measurements(struct SensorMeasurements* measurements);

#endif // __SENSOR_H

