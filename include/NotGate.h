#ifndef NOT_GATE_H
#define NOT_GATE_H

#include "Gate.h"

class NotGate : public Gate {
public:
    NotGate();

    void evaluate() override;
};

#endif