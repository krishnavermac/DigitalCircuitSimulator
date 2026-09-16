#include "FullAdder.h"

FullAdder::FullAdder()
    : Gate("FULL_ADDER", 3, 2) {
}

void FullAdder::evaluate() {
    int a = inputs[0];
    int b = inputs[1];
    int carryIn = inputs[2];

    outputs[0] = a ^ b ^ carryIn;

    outputs[1] =
        (a & b) |
        (b & carryIn) |
        (a & carryIn);
}