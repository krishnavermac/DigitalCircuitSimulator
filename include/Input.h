#ifndef INPUT_H
#define INPUT_H

#include "Gate.h"

class Input : public Gate {
public:
    Input();

    void setValue(int value);

    void evaluate() override;
};

#endif