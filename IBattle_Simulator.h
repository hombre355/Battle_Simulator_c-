#ifndef IBATTLE_SIMULATOR_H
#define IBATTLE_SIMULATOR_H

#include "ITransformer.h"

class IBattle_Simulator
{
public:
    virtual ~IBattle_Simulator() = default;

    virtual std::string battle(const ITransformer& transformer1, const ITransformer& transformer2) = 0;
};

#endif IBATTLE_SIMULATOR_H
