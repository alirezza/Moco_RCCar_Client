#include "DCMotor.hpp"

#define MOTORPINJUMPER 15
#define MOTORPINFORWARD 13
#define MOTORPINBACK 12

DCMotor::DCMotor(){
    DCMotor::setup();
}


void DCMotor::setup() {
    pinMode(MOTORPINJUMPER, OUTPUT);
    pinMode(MOTORPINFORWARD, OUTPUT);
    pinMode(MOTORPINBACK, OUTPUT);
}



bool DCMotor::rotate(int speed) {
    if (speed > -300 && speed < 300)
    {

        Serial.print(speed);
        if (speed == 0)
        {   
            digitalWrite(MOTORPINFORWARD, LOW);
            digitalWrite(MOTORPINBACK, LOW);
            analogWrite(MOTORPINJUMPER,0);
            return  true;
        }
        
        if(speed>0){
            digitalWrite(MOTORPINFORWARD, HIGH);
            digitalWrite(MOTORPINBACK, LOW);
            analogWrite(MOTORPINJUMPER,speed);
        return  true;
        
        }
        else if(speed<0){
            digitalWrite(MOTORPINFORWARD, LOW);
            digitalWrite(MOTORPINBACK, HIGH);
            analogWrite(MOTORPINJUMPER, speed);
        return  true;
        
        }
    }
       return false;

}


