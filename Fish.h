#pragma once
#include "Animal.h"

class Fish : public Animal {
private:
    bool isDeepWater;

public:
    Fish(const string& name, bool isPredator, bool isDeepWater)
        : Animal(name, isPredator), isDeepWater(isDeepWater) {}

    bool getIsDeepWater() const { return isDeepWater; }
    void setIsDeepWater(bool isDeepWater) { this->isDeepWater = isDeepWater; }

    string showDescription() const override {
        return "Fish: " + name + ", Deep Water: " + (isDeepWater ? "Yes" : "No");
    }
};
