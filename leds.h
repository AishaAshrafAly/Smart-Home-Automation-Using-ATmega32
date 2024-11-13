/*
 * leds.h
 *
 *  Created on: Oct 8, 2024
 *      Author: aisha
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "std_types.h"


#define LOGIC_MODE 1

#define RED_LED_PORT_ID                 PORTB_ID
#define RED_LED_PIN_ID                  PIN5_ID

#define GREEN_LED_PORT_ID               PORTB_ID
#define GREEN_LED_PIN_ID                PIN6_ID

#define BLUE_LED_PORT_ID                PORTB_ID
#define BLUE_LED_PIN_ID                 PIN7_ID

#if(LOGIC_MODE == 1)
   #define LED_ON                      LOGIC_HIGH
   #define LED_OFF                     LOGIC_LOW
#elif(LOGIC_MODE == 0)
   #define LED_ON                      LOHIC_LOW
   #define LED_OFF                     LOGIC_HIGH
#endif

typedef enum
{
	RED,GREEN,BLUE
}LED_ID;


 void LEDS_init(void);


 void LED_on(LED_ID id);


 void LED_off(LED_ID id);


 void Automatic_Lighting_Control(uint8 Intensity);


#endif
