
#include "Battle_Simulator.h"
#include <cstdlib>
#include <ctime>

std::string BattleSimulator::battle(const Transformer& t1, const Transformer& t2)
{
    // Randomly determine the winner
    //std::srand(std::time(0)); // Initialize random seed
    if (t1.getStrength() > t2.getStrength())
    {

        const_cast<Transformer&>(t1).winBattle(); // Increment the wins for transformer1
        const_cast<Transformer&>(t2).loseBattle(); // Increment losses for transformer2
        return t1.getName() + " wins!";
    }
    else if (t1.getStrength() < t2.getStrength())
    {
        const_cast<Transformer&>(t2).winBattle();
        const_cast<Transformer&>(t1).loseBattle();
        return t2.getName() + " wins!";
    }
    else
    {
        return "It's a draw!";
    }
}
