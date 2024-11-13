/*
 * pwm.h
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"


#define PWM_E_PORT_ID                  PORTB_ID
#define PWM_E_PIN_ID                   PIN3_ID

#define MOTOR_MAX_SPEED                  100
#define PWM_MAX_OUTPUT                   255


void PWM_Timer0_Start(void);
void duty_cycle(uint8 duty_cycle);


#endif
