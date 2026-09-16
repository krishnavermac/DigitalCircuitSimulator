#ifndef OR_GATE_H
#define OR_GATE_H

#include "Gate.h"

class OrGate : public Gate {
public:
    OrGate();

    void evaluate() override;
};

#endif