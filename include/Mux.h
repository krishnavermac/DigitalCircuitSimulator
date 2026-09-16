#ifndef MUX_H
#define MUX_H

#include "Gate.h"

class Mux : public Gate {
public:
    Mux();

    void evaluate() override;
};

#endif