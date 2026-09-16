#ifndef DEMUX_H
#define DEMUX_H

#include "Gate.h"

class Demux : public Gate {
public:
    Demux();

    void evaluate() override;
};

#endif