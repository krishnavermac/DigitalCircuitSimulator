#ifndef NAND_GATE_H
#define NAND_GATE_H

#include "Gate.h"

class NandGate : public Gate {
public:
    NandGate();

    void evaluate() override;
};

#endif