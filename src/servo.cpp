#include "servo.hpp"

#define MAX_ANGLE_LEFT 180
#define MAX_ANGLE_RIGHT 0

ServoMotor::ServoMotor(const unsigned int SERVO_GPIO_PIN) {

  m_servo.attach(SERVO_GPIO_PIN);

}

void ServoMotor::setup(const unsigned int SERVO_GPIO_PIN) {

  m_servo.attach(SERVO_GPIO_PIN);

}

bool ServoMotor::steer(int new_angle) {
  if (new_angle <= MAX_ANGLE_LEFT  && new_angle >= MAX_ANGLE_RIGHT) {
    m_servo.write(new_angle);
    return true;
  } else {
    //Serial.println("new_angle not between MAX_RIGHT and MAX_LEFT");
    //Serial.printf("new_angle is %i \n", new_angle);
    return false;
  }
}

void ServoMotor::turnSteering() {

  int angle = -33;

    for(; angle <= 147; angle++) {
    Serial.println(angle);
    m_servo.write(angle);
    }

    for(; angle >= -33; angle--) {
    Serial.println(angle);
    m_servo.write(angle);
    }
}

//   servo.write(147); //Anschlag links
//   delay(1000);
  
//   servo.write(57); //Mitte
//   delay(1000);
  
//   servo.write(-33); //Anschlag rechts
//   delay(1000);
