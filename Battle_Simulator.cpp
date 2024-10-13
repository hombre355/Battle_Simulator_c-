
#include "Battle_Simulator.h"
#include <cstdlib>
#include <ctime>

std::string BattleSimulator::battle(const ITransformer& transformer1, const ITransformer& transformer2)
{
    // Randomly determine the winner
    std::srand(std::time(0)); // Initialize random seed
    if (transformer1.getStrength() > transformer2.getStrength())
    {
        const_cast<ITransformer&>(transformer1).winBattle(); // Increment the wins for transformer1
        const_cast<ITransformer&>(transformer2).loseBattle(); // Increment losses for transformer2
        return transformer1.getName() + " wins!";
    }
    else if (transformer1.getStrength() < transformer2.getStrength())
    {
        const_cast<ITransformer&>(transformer2).winBattle();
        const_cast<ITransformer&>(transformer1).loseBattle();
        return transformer2.getName() + " wins!";
    }
    else
    {
        return "It's a draw!";
    }
}
