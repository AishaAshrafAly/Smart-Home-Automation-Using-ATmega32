/*
 * FlameSensor.c
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */


#include "common_macros.h" /* For GET_BIT Macro */
#include "flame_sensor.h"
#include "gpio.h"
#include "buzzer.h"
#include "lcd.h"

unsigned char prev_value = 0;
unsigned char flag = 0;

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID, PIN_INPUT);
}


 uint8 FlameSensor_getValue(void)
 {
	 uint8 value;
	 value=GPIO_readPin(FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID);
	 return value;
 }


 void FlameSensor(uint8 value)
 {
	 if((prev_value==0 && value==1) || (prev_value==1 && value==0))
	 {
		 flag=0;
	 }
	 if(value==1)
	 {
		 Buzzer_on();
		 if(flag==0)
		 {
			 LCD_clearScreen();
			 LCD_displayString("Critical alert!");
		 }
		 flag=1;
	 }
	 else
	 {
		 Buzzer_off();
		 if(flag==0)
		 {
			 LCD_clearScreen();
		     LCD_moveCursor(0,4);
		     LCD_displayString("FAN IS ");
	   	     LCD_moveCursor(1,0); /* Move the cursor to the second row */
		     LCD_displayString("TEMP=   LDR=   %");
		 }
		 flag=1;
	 }
	 prev_value=value;
 }
