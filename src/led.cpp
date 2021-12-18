#include "led.hpp"

// inverse logic
#define ON LOW
#define OFF HIGH

LED::LED(const unsigned int LED_PIN) 
    : m_LED_PIN(LED_PIN) {}

void LED::setup () {
    pinMode(m_LED_PIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

void LED::blinkLED(const unsigned int delayTime) {
    digitalWrite(m_LED_PIN, ON);   // Turn the LED on by making the voltage LOW
    delay(delayTime);                 // Wait
    digitalWrite(m_LED_PIN, OFF);  // Turn the LED off by making the voltage HIGH
    delay(delayTime);                 // Wait
}
