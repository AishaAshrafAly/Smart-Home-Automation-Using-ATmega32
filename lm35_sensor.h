/*
 * lm35_sensor.h
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"


#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

#define LM35_SENSOR_PORT_ID                 PORTA_ID
#define LM35_SENSOR_PIN_ID                  PIN1_ID


uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
