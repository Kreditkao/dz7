#pragma once
#include "Animal.h"

class Bird : public Animal {
private:
    double flightSpeed;

public:
    Bird(const string& name, bool isPredator, double flightSpeed)
        : Animal(name, isPredator), flightSpeed(flightSpeed) {}

    double getFlightSpeed() const { return flightSpeed; }
    void setFlightSpeed(double flightSpeed) { this->flightSpeed = flightSpeed; }

    string showDescription() const override {
        return "Bird: " + name + ", Flight Speed: " + to_string(flightSpeed) + " km/h";
    }
};
