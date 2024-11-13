/*
 * adc.c
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */


#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */


void ADC_init(void)
{

	ADMUX =(1<<REFS1) | (1<<REFS0);


	ADCSRA = (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}

uint16 ADC_readChannel(uint8 channel_num)
{

	ADMUX =(ADMUX & 0xE0) |(channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
