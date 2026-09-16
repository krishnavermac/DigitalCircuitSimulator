#include "Demux.h"

Demux::Demux()
    : Gate("DEMUX", 2) {
}

void Demux::evaluate() {
    int input = inputs[0];
    int select = inputs[1];

    if (select == 0) {
        outputs[0] = input;
    } else {
        outputs[0] = 0;
    }
}