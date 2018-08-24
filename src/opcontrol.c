/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "chassis.h"

#define BOTTOM_MOTOR 4
#define MIDDLE_MOTOR 5
#define CLAW_MOTOR 6

void operatorControl() {
	while (1) {
		int power, turn;
	  power = joystickGetAnalog(2, 2); // vertical axis on right joystick
	  turn  = joystickGetAnalog(1, 4); // horizontal axis on left joystick
	  chassisSet(power + turn, power - turn);

		if(joystickGetDigital(1, 5, JOY_UP)){ // if button 5U is pressed, raise forearm
			motorSet(MIDDLE_MOTOR, 127);
		}
		else if(joystickGetDigital(1, 5, JOY_DOWN)){ // if button 5D is pressed, lower forearm
			motorSet(MIDDLE_MOTOR, -127);
		}
		else{
			motorSet(MIDDLE_MOTOR, 0);
		}
	}
}
