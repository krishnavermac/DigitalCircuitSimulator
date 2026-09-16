#include "Input.h"

Input::Input()
    : Gate("INPUT", 0) {
}

void Input::setValue(int value) {
    outputs[0] = value ? 1 : 0;
}

void Input::evaluate() {
}