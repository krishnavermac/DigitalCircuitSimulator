#include "OrGate.h"

OrGate::OrGate()
    : Gate("OR", 2) {
}

void OrGate::evaluate() {
    outputs[0] = inputs[0] | inputs[1];
}