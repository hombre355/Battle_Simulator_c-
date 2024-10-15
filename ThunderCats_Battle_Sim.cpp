#include "ThunderCats_Battle_Sim.h"

std::string ThunderCats_Battle_Sim::battle(const ThunderCats& t1, const ThunderCats& t2)
{
    if (t1.getStrength() > t2.getStrength())
    {
        const_cast<ThunderCats&>(t1).winBattle();
        const_cast<ThunderCats&>(t2).loseBattle();
        return t1.getName() + " wins with " + t1.getWeapon() + "!";
    }
    else if (t1.getStrength() < t2.getStrength())
    {
        const_cast<ThunderCats&>(t2).winBattle();
        const_cast<ThunderCats&>(t1).loseBattle();
        return t2.getName() + " wins with " + t1.getWeapon() + "!";
    }
    else
    {
        return "It's a draw!";
    }
}
