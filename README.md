# Smart-Home-Automation-Using-ATmega32
This repository contains the code, schematics, and documentation for a Smart Home Automation System built using an ATmega32 microcontroller. The project integrates multiple sensors and control mechanisms to automate lighting, fan speed, and fire detection with real-time status displayed on an LCD.

Project Overview
The Smart Home Automation System controls lighting, fan speed, and fire safety alerts based on environmental conditions:

- Lighting Control: Uses an LDR to adjust LED indicators based on ambient light levels.
- Fan Speed Control: Adjusts fan speed in response to room temperature, measured by an LM35 sensor.
- Fire Detection: Detects fire with a flame sensor and triggers an alarm.
- LCD Display: Shows real-time data, including temperature, light intensity, fan status, and fire alerts.

Features
- Automatic Lighting Control: Adjusts LEDs based on LDR light intensity readings.
- Automatic Fan Speed Control: Uses PWM to control fan speed based on temperature thresholds.
- Fire Detection & Alert: Displays "Critical alert!" on LCD and activates a buzzer when fire is detected.
- Real-Time Display: Displays fan status, temperature, and light intensity on a 16x2 LCD.

Hardware Components
- Microcontroller: ATmega32
- Sensors: LDR (Light Sensor), LM35 (Temperature Sensor), Flame Sensor
- Actuators: Motor (Fan Control), LEDs, Buzzer
- Display: 16x2 LCD for real-time information

Layered Architecture
- The code is organized using a layered architecture, with modular drivers for ADC, GPIO, PWM, LCD, temperature sensor, LDR, LED, DC motor, flame sensor, and buzzer control.

Drivers & Functions
Each driver provides core functionality, such as initializing sensors, handling input/output control, and setting up ADC/PWM configurations. Highlights include:

- ADC Driver: Reads analog data from sensors.
- GPIO Driver: Controls pin direction and states.
- PWM Driver: Generates PWM signals to control fan speed.
- LCD Driver: Displays system information.
- DC Motor Driver: Controls fan rotation and speed.
- Flame Sensor Driver: Detects fire conditions.
- Buzzer Driver: Triggers alerts during fire detection.
