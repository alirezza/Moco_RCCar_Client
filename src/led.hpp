#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

class LED {

public:
    LED() = delete;
    LED(const unsigned int LED_PIN);
    void setup ();
    void blinkLED(const unsigned int delayTime);

private:
    unsigned int m_LED_PIN = -1;

};

#endif  // LED_HPP
