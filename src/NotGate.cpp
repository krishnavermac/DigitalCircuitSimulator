#include "NotGate.h"

NotGate::NotGate()
    : Gate("NOT", 1) {
}

void NotGate::evaluate() {
    outputs[0] = !inputs[0];
}