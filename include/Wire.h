#ifndef WIRE_H
#define WIRE_H

#include "Gate.h"

class Wire {
private:
    Gate* source;
    int sourceOutput;

    Gate* destination;
    int destinationInput;

public:
    Wire(
        Gate* source,
        int sourceOutput,
        Gate* destination,
        int destinationInput
    );

    void propagate();

    Gate* getSource() const;
    Gate* getDestination() const;
};

#endif