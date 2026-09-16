#include "XnorGate.h"

XnorGate::XnorGate()
    : Gate("XNOR", 2) {
}

void XnorGate::evaluate() {
    outputs[0] = !(inputs[0] ^ inputs[1]);
}