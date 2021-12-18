#ifndef DCMOTOR_HPP
#define DCMOTOR_HPP

#include <Arduino.h>

class DCMotor {
public:
    void setup();
    bool rotate(int speed, bool direction);
    int toPWM(int value);

private:
    // int member variables

};

#endif  // DCMOTOR_HPP
