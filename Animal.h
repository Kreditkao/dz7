#pragma once

#include <string>
#include "ZooException.h"
#include "NameException.h"

using namespace std;

class Animal {
protected:
    string name;
    bool isPredator;

public:
    Animal(const string& name, bool isPredator) {
        if (name.empty()) {
            throw NameException();
        }
        this->name = name;
        this->isPredator = isPredator;
    }

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    bool getIsPredator() const { return isPredator; }
    void setIsPredator(bool isPredator) { this->isPredator = isPredator; }

    virtual string showDescription() const = 0;
};
