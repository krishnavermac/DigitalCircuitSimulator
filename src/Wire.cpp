#include "Wire.h"

Wire::Wire(
    Gate* source,
    int sourceOutput,
    Gate* destination,
    int destinationInput
)
    : source(source),
      sourceOutput(sourceOutput),
      destination(destination),
      destinationInput(destinationInput) {
}

void Wire::propagate() {
    destination->setInput(
        destinationInput,
        source->getOutput(sourceOutput)
    );
}

Gate* Wire::getSource() const {
    return source;
}

Gate* Wire::getDestination() const {
    return destination;
}