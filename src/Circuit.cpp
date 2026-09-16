#include "Circuit.h"

#include <iostream>
#include <unordered_map>
#include <queue>

void Circuit::connect(
    Gate* source,
    int sourceOutput,
    Gate* destination,
    int destinationInput
) {
    wires.push_back(
        std::make_unique<Wire>(
            source,
            sourceOutput,
            destination,
            destinationInput
        )
    );
}

void Circuit::simulate() {

    std::unordered_map<Gate*, int> indegree;

    for (auto& gate : gates) {
        indegree[gate.get()] = 0;
    }

    for (auto& wire : wires) {
        indegree[wire->getDestination()]++;
    }

    std::queue<Gate*> q;

    for (auto& gate : gates) {
        if (indegree[gate.get()] == 0) {
            q.push(gate.get());
        }
    }

    int processed = 0;

    while (!q.empty()) {

        Gate* current = q.front();
        q.pop();

        current->evaluate();
        processed++;

        for (auto& wire : wires) {

            if (wire->getSource() == current) {

                wire->propagate();

                Gate* destination = wire->getDestination();

                indegree[destination]--;

                if (indegree[destination] == 0) {
                    q.push(destination);
                }
            }
        }
    }

    if (processed != static_cast<int>(gates.size())) {
        std::cerr << "Error: Circuit contains a cycle.\n";
    }
}