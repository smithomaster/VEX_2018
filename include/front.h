#define _FRONT_H_
#define LEFT_FRONT 3
#define RIGHT_FRONT 8
#include "main.h"

void frontChassis(int rightFront, int leftFront) {
  motorSet(LEFT_FRONT, leftFront);
  motorSet(RIGHT_FRONT, rightFront);
}
