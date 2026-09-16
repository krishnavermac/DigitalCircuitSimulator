#ifndef AND_GATE_H
#define AND_GATE_H

#include "Gate.h"

class AndGate : public Gate {
public:
    AndGate();

    void evaluate() override;
};

#endif
