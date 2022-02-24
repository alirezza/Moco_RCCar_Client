#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <Arduino.h>
#include "servo.hpp"
#include "DCMotor.hpp"
#include "UDPServer.hpp"

struct VehicleData {

    const unsigned int SERVO_GPIO_PIN;
    // const unsigned int DC_GPIO_PIN;

};

class Vehicle {

public:
    static Vehicle *shared() {
        if (!instance) {
            instance = new Vehicle();
        }
        return instance;
    };
    void setup();
    void setup(VehicleData vehicleSpecification, ServerData vehicleServer);
    void maneuver();
    void maneuver(DrivingData newManeuver);
private:
    Vehicle();
    Vehicle(VehicleData vehicleSpecification, ServerData vehicleServer);
    static Vehicle *instance;
    DCMotor *m_vehicleMotor;
    ServoMotor *m_vehicleSteering;
    UdpServer *m_vehicleServer;
    DrivingData m_drivingData = { .vehicleAngle = 0,
                                .vehicleAcceleration = 0 };
};

#endif  // VEHICLE_HPP
