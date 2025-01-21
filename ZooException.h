#pragma once
#include <string>
using namespace std;

class ZooException {
public:
    virtual string showMessage() const = 0;
};
