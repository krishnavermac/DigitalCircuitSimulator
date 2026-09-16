#include "NandGate.h"

NandGate::NandGate()
    : Gate("NAND", 2) {
}

void NandGate::evaluate() {
    outputs[0] = !(inputs[0] & inputs[1]);
}