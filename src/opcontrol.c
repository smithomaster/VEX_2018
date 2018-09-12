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
#include "front.h"
#define BOTTOM_MOTOR 4
#define MIDDLE_MOTOR 5
#define CLAW_MOTOR 6
#define LEFT_FRONT 3
#define RIGHT_FRONT 8

void operatorControl() {
	while (1) {
		int leftFront;
		int leftBack;
		int rightFront;
		int rightBack;
		while(1) {
			rightFront = joystickGetAnalog(1, 2); // vertical axis on right joystick
			rightBack = rightFront;
		  leftFront  = joystickGetAnalog(1, 3); // vertical axis on left joystick
			leftBack = leftFront;
			rightBack = rightBack * -1;
			rightFront = rightFront * -1;

			backChassis(rightBack, leftBack);
			frontChassis(rightFront, leftFront);

			if(joystickGetDigital(1, 5, JOY_UP)){ // if button 5U is pressed, raise forearm
				motorSet(CLAW_MOTOR, 100);
			}
			else if(joystickGetDigital(1, 5, JOY_DOWN)){ // if button 5D is pressed, lower forearm
				motorSet(CLAW_MOTOR, -50);
			}
			else{
				motorSet(CLAW_MOTOR, 0);
			}

			if(joystickGetDigital(1,6, JOY_UP)){
				motorSet(BOTTOM_MOTOR, 127);
			}
			else if(joystickGetDigital(1, 6, JOY_DOWN)){
				motorSet(BOTTOM_MOTOR, -127);
			}
			else{
				motorSet(BOTTOM_MOTOR, 0);
			}

			if(joystickGetDigital(1, 8, JOY_UP)){
				motorSet(MIDDLE_MOTOR, 127);
			}
			else if(joystickGetDigital(1,8,JOY_DOWN)){
				motorSet(MIDDLE_MOTOR, -127);
			}
			else{
				motorSet(MIDDLE_MOTOR, 0);
			}
		}
	}
}
