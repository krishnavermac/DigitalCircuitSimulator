#include "HalfAdder.h"

HalfAdder::HalfAdder()
    : Gate("HALF_ADDER", 2, 2) {
}

void HalfAdder::evaluate() {
    outputs[0] = inputs[0] ^ inputs[1];
    outputs[1] = inputs[0] & inputs[1];
}