#include "DCMotor.hpp"

#define  MOTORPINJUMPER 15
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

    if(speed>0){
      return  rotate((unsigned int)speed,true);
    
    }
    else if(speed<=0){
        
      return  rotate(-1 * speed,false);
      
    }
       return false;

}

bool DCMotor::rotate(int speed, bool direction) {
    
    if(direction == true){
        digitalWrite(MOTORPINFORWARD, HIGH);
        digitalWrite(MOTORPINBACK, LOW);
        analogWrite(MOTORPINJUMPER,speed);
    
    }else if(direction == false){
         
        digitalWrite(MOTORPINFORWARD, LOW);
        digitalWrite(MOTORPINBACK, HIGH);
        analogWrite(MOTORPINJUMPER, speed);
        Serial.println(speed);
    }
    return true;   

}

