/*
 * motor.c
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */


#include "common_macros.h" /* For GET_BIT Macro */
#include "motor.h"
#include "gpio.h"
#include "lcd.h"
#include "pwm.h"


void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);

	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);

	duty_cycle(0);
}


void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	if(state==CW) //clockwise
	{
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
	else if(state==A_CW) //anti_clockwise
	{
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
	}
	else if(state==STOP) //stop
	{
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
	duty_cycle(speed);
}


void Automatic_Fan_Speed_Control(DcMotor_State state, uint8 Temperature)
{
	LCD_moveCursor(1,5);
	LCD_intgerToString(Temperature);

	if(Temperature>=40)
    {
		DcMotor_Rotate(state, 100);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
    }
	else if((Temperature>=35) && (Temperature<40))
	{
		DcMotor_Rotate(state, 75);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
	}
	else if((Temperature>=30) && (Temperature<35))
	{
		DcMotor_Rotate(state, 50);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
	}
	else if((Temperature>=25) && (Temperature<30))
	{
		DcMotor_Rotate(state, 25);
		LCD_moveCursor(0,11);
		LCD_displayString("ON ");
	}
	else
	{
		DcMotor_Rotate(state, 0);
		LCD_moveCursor(0,11);
		LCD_displayString("OFF");
	}
}
