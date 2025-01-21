#pragma once
#include "ZooException.h"

class PredatorException : public ZooException {
public:
    string showMessage() const override {
        return "Error: Can't add a predator to an enclosure with non-predatory animals.";
    }
};
