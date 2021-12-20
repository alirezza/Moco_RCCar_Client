#include "vehicle.hpp"

#define LOCALPORT 8888

Vehicle::Vehicle() { }

Vehicle *Vehicle::instance = 0;

// void Vehicle::setup() {
//     m_vehicleSteering.setup(2);
//     m_vehicleServer.setup(LOCALPORT);
//     // vehicleMotor.setup();
// }

void Vehicle::setup(VehicleData vehicleSpecification, ServerData vehicleServer) {
    m_vehicleServer = new UdpServer(vehicleServer);
    m_vehicleSteering = new ServoMotor(vehicleSpecification.SERVO_GPIO_PIN);
    m_vehicleMotor = new DCMotor();
}


// Vehicle::Vehicle(VehicleData vehicleSpecification, ServerData vehicleServer) 
//     : m_vehicleSteering(vehicleSpecification.SERVO_GPIO_PIN), m_vehicleServer(vehicleServer) {
//     // m_vehicleServer = UdpServer(vehicleServer);
//     // m_vehicleSteering = ServoMotor(vehicleSpecification.SERVO_GPIO_PIN);
//     // m_vehicleMotor = DCMotor(vehicleSpecification.);
// }

void Vehicle::maneuver() {
    DrivingData newManeuver = m_vehicleServer->returnReceivedMessage();
    if ((m_vehicleSteering->steer(newManeuver.vehicleAngle)) && m_vehicleMotor->rotate(newManeuver.vehicleAcceleration,true)) {
        m_drivingData.vehicleAcceleration = newManeuver.vehicleAcceleration;
        m_drivingData.vehicleAngle = newManeuver.vehicleAngle;
    }
}

void Vehicle::maneuver(DrivingData newManeuver) {
    if (m_vehicleSteering->steer(newManeuver.vehicleAngle)) {
        m_drivingData.vehicleAngle = newManeuver.vehicleAngle;
    }
}
