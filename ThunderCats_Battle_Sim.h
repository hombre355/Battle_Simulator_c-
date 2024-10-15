#ifndef THUNDERCATS_BATTLE_SIM_H
#define THUNDERCATS_BATTLE_SIM_H

#include "IBattle_Simulator.h"
#include "ThunderCats.h"


class ThunderCats_Battle_Sim : public IBattle_Simulator<ThunderCats>
{
public:

    /**********************************************************
    *
    * This function overrides the virtual function for battle.
    * It takes two transformer objects, uses their strength
    * value and whoever has the bigger strength value is the
    * winner. It the value is the same, then it is a draw.
    *
    ***********************************************************/
    std::string battle(const ThunderCats& t1, const ThunderCats& t2) override;
};

#endif //THUNDERCATS_BATTLE_SIM_H
