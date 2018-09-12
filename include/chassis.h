#define _CHASSIS_H_

#include "main.h"

// Sets the speeds of the left and right wheels of the chassis
void backChassis(int rightBack, int leftBack){
  motorSet(1, leftBack);
  motorSet(10, rightBack);
}
