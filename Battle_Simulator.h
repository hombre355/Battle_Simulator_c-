#ifndef BATTLE_SIMULATOR_H
#define BATTLE_SIMULATOR_H

#include "IBattle_Simulator.h"
#include "Transformer.h"

class BattleSimulator : public IBattle_Simulator<Transformer>
{
public:
    std::string battle(const Transformer& t1, const Transformer& t2) override;
};

#endif
