#ifndef GATE_H
#define GATE_H

#include <string>
#include <vector>

class Gate {
protected:
    std::string name;
    std::vector<int> inputs;
    std::vector<int> outputs;

public:
    Gate(const std::string& name, int inputCount, int outputCount = 1);

    virtual ~Gate() = default;

    virtual void evaluate() = 0;

    void setInput(int index, int value);

    int getInput(int index) const;

    int getOutput(int index = 0) const;

    std::string getName() const;
};

#endif