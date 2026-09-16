#include "AndGate.h"

AndGate::AndGate()
    : Gate("AND", 2) {
}

void AndGate::evaluate() {
    outputs[0] = inputs[0] & inputs[1];
}