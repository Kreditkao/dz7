#pragma once
#include "ZooException.h"

class NameException : public ZooException {
public:
    string showMessage() const override {
        return "It is impossible to create a creature - the name is not indicated.";
    }
};
