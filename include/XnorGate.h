#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include "Gate.h"

class XnorGate : public Gate {
public:
    XnorGate();

    void evaluate() override;
};

#endif