/*
 * pwm.c
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */


#include "common_macros.h" /* For GET_BIT Macro */
#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"



void PWM_Timer0_Start(void)
{
	TCNT0 = 0;


	GPIO_setupPinDirection(PWM_E_PORT_ID, PWM_E_PIN_ID ,PIN_OUTPUT);


	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);

}

void duty_cycle(uint8 duty_cycle)
{
	OCR0  = (uint8)(((uint32)duty_cycle*PWM_MAX_OUTPUT)/(MOTOR_MAX_SPEED)); // Set Compare Value
}
