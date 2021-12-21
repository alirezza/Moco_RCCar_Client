#include "DCMotor.hpp"

#define  MOTORPINJUMPER 12
#define MOTORPINFORWARD 13
#define MOTORPINBACK 15

DCMotor::DCMotor(){
    DCMotor::setup();
}


void DCMotor::setup() {
    pinMode(MOTORPINJUMPER, OUTPUT);
    pinMode(MOTORPINFORWARD, OUTPUT);
    pinMode(MOTORPINBACK, OUTPUT);
}



bool DCMotor::rotate(int speed) {
    if(speed>0){
    digitalWrite(MOTORPINFORWARD, HIGH);
    digitalWrite(MOTORPINBACK, LOW);
    analogWrite(MOTORPINJUMPER, speed);
    
    }else{
    digitalWrite(MOTORPINFORWARD, LOW);
    digitalWrite(MOTORPINBACK, HIGH);
    analogWrite(MOTORPINJUMPER, speed);
    }
    return true;   

}

