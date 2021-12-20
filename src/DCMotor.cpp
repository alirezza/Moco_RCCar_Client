#include "DCMotor.hpp"

#define  MOTORPINJUMPER 12
#define MOTORPINFORWARD 13
#define MOTORPINBACK 15

DCMotor::DCMotor(){}


void DCMotor::setup() {
pinMode(MOTORPINJUMPER, OUTPUT);
pinMode(MOTORPINFORWARD, OUTPUT);
pinMode(MOTORPINBACK, OUTPUT);
}



bool DCMotor::rotate(int speed, bool direction) {
    if(direction){
    analogWrite(MOTORPINJUMPER, speed);
    analogWrite(MOTORPINFORWARD, speed);
    
    }else{
    analogWrite(MOTORPINJUMPER, speed);
    analogWrite(MOTORPINBACK, speed);
    }

    return true;
}

