#include "DCMotor.hpp"

#define MOTOR_POWER D1
#define MOTOR_DIRECTION D3

void DCMotor::setup() {
    pinMode(MOTOR_POWER, OUTPUT);  // D1
    pinMode(MOTOR_DIRECTION, OUTPUT);  // D3
}


bool DCMotor::rotate(int speed, bool direction) {
    analogWrite(MOTOR_POWER, toPWM(speed));
    digitalWrite(MOTOR_DIRECTION, direction);
    return true;
}

int DCMotor::toPWM(int value) {
    return map(value, 0, 100, 0, 255);
}
