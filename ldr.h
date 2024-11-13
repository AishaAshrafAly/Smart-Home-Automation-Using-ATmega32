/*
 * ldr.h
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"


#define LDR_CHANNEL_ID                    0
#define LDR_SENSOR_MAX_VOLT_VALUE         2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY    100

#define LDR_SENSOR_PORT_ID                 PORTA_ID
#define LDR_SENSOR_PIN_ID                  PIN0_ID


 uint16 LDR_getLightIntensity(void);


#endif /* LDR_H_ */
