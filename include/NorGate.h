#ifndef NOR_GATE_H
#define NOR_GATE_H

#include "Gate.h"

class NorGate : public Gate {
public:
    NorGate();

    void evaluate() override;
};

#endif