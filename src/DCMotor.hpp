#ifndef DCMOTOR_HPP
#define DCMOTOR_HPP

#include <Arduino.h>

class DCMotor {
public:
    DCMotor();
    void setup();
    bool rotate(int speed);
    

private:
    // int member variables

};

#endif  // DCMOTOR_HPP
