/*
 * LDR.c
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */


#include "common_macros.h" /* For GET_BIT Macro */
#include "ldr.h"
#include "adc.h"


 uint16 LDR_getLightIntensity(void)
 {
	 uint8 Light_Intensity = 0;

	 uint16 adc_value = 0;

	 adc_value = ADC_readChannel(LDR_CHANNEL_ID );

	 Light_Intensity= (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

 	return Light_Intensity;
 }
