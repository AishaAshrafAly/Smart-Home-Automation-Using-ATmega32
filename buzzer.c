/*
 * Buzzer.c
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */


#include "common_macros.h" /* For GET_BIT Macro */
#include "buzzer.h"
#include "gpio.h"


void Buzzer_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * BUZZER ON:
 * 1.
 */
 void Buzzer_on(void)
 {
	 GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
 }

 /*
  * Description :
  * BUZZER OFF:
  * 1.
  */
 void Buzzer_off(void)
 {
	 GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
 }
