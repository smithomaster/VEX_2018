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

void operatorControl() {
	while (1) {
		int power, turn;
		while (1) {
		  power = joystickGetAnalog(2, 2); // vertical axis on right joystick
		  turn  = joystickGetAnalog(1, 1); // horizontal axis on left joystick
		  chassisSet(power + turn, power - turn);
		}
	}
}
