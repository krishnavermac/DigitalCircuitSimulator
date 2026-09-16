#include "Gate.h"

Gate::Gate(
    const std::string& name,
    int inputCount,
    int outputCount
)
    : name(name),
      inputs(inputCount, 0),
      outputs(outputCount, 0) {
}

void Gate::setInput(int index, int value) {
    if (index >= 0 && index < static_cast<int>(inputs.size())) {
        inputs[index] = value ? 1 : 0;
    }
}

int Gate::getInput(int index) const {
    if (index >= 0 && index < static_cast<int>(inputs.size())) {
        return inputs[index];
    }

    return 0;
}

int Gate::getOutput(int index) const {
    if (index >= 0 && index < static_cast<int>(outputs.size())) {
        return outputs[index];
    }

    return 0;
}

std::string Gate::getName() const {
    return name;
}