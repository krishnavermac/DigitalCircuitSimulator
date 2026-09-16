#include "Mux.h"

Mux::Mux()
    : Gate("MUX", 3) {
}

void Mux::evaluate() {
    int select = inputs[2];

    if (select == 0) {
        outputs[0] = inputs[0];
    } else {
        outputs[0] = inputs[1];
    }
}