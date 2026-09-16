#ifndef OUTPUT_H
#define OUTPUT_H

#include "Gate.h"

class Output : public Gate {
public:
    Output();

    void evaluate() override;
};

#endif