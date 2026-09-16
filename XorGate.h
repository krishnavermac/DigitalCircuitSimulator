#ifndef XOR_GATE_H
#define XOR_GATE_H

#include "Gate.h"

class XorGate : public Gate {
public:
    XorGate();

    void evaluate() override;
};

#endif