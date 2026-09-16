#ifndef FULL_ADDER_H
#define FULL_ADDER_H

#include "Gate.h"

class FullAdder : public Gate {
public:
    FullAdder();

    void evaluate() override;
};

#endif