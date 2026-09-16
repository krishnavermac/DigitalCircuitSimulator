#include "Output.h"

Output::Output()
    : Gate("OUTPUT", 1) {
}

void Output::evaluate() {
    outputs[0] = inputs[0];
}