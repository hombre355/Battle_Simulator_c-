#ifndef BATTLE_SIMULATOR_H
#define BATTLE_SIMULATOR_H

#include "IBattle_Simulator.h"
#include "ITransformer.h"


class BattleSimulator : public IBattle_Simulator
{
public:
    std::string battle(const ITransformer& transformer1, const ITransformer& transformer2) override;
};

#endif
