#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <memory>
#include <vector>
#include <utility>

#include "Gate.h"
#include "Wire.h"

class Circuit {
private:
    std::vector<std::unique_ptr<Gate>> gates;
    std::vector<std::unique_ptr<Wire>> wires;

public:
    template <typename T, typename... Args>
    T* addGate(Args&&... args) {
        auto gate = std::make_unique<T>(
            std::forward<Args>(args)...
        );

        T* ptr = gate.get();

        gates.push_back(std::move(gate));

        return ptr;
    }

    void connect(
        Gate* source,
        int sourceOutput,
        Gate* destination,
        int destinationInput
    );

    void simulate();
};

#endif