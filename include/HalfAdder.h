#ifndef HALF_ADDER_H
#define HALF_ADDER_H

#include "Gate.h"

class HalfAdder : public Gate {
public:
    HalfAdder();

    void evaluate() override;
};

#endif