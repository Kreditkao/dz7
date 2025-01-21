#pragma once
#include "ZooException.h"

class MaxCapacityException : public ZooException {
public:
    string showMessage() const override {
        return "Error: Can't add more animals to the enclosure. Maximum capacity reached.";
    }
};
