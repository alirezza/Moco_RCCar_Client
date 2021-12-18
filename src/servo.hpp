#ifndef SERVO_HPP
#define SERVO_HPP

#include <Servo.h>

class ServoMotor {
public:
    ServoMotor();
    ServoMotor(const unsigned int SERVO_GPIO_PIN);
    void setup(const unsigned int SERVO_GPIO_PIN); // GPIO 2 -> PIN D4
    bool steer(int angle);
    // readServo()
    void turnSteering();

    Servo m_servo;
};

#endif  // SERVO_HPP
