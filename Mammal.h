#pragma once
#include "Animal.h"

class Mammal : public Animal {
private:
    string habitat;

public:
    Mammal(const string& name, bool isPredator, const string& habitat)
        : Animal(name, isPredator), habitat(habitat) {}

    string getHabitat() const { return habitat; }
    void setHabitat(const string& habitat) { this->habitat = habitat; }

    string showDescription() const override {
        return "Mammal: " + name + ", Habitat: " + habitat;
    }
};
