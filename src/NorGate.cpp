#include "NorGate.h"

NorGate::NorGate()
    : Gate("NOR", 2) {
}

void NorGate::evaluate() {
    outputs[0] = !(inputs[0] | inputs[1]);
}