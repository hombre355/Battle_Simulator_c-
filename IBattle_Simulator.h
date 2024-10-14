#ifndef IBATTLE_SIMULATOR_H
#define IBATTLE_SIMULATOR_H

#include <string>

template <typename T>
class IBattle_Simulator
{
public:
    virtual ~IBattle_Simulator() = default;

    virtual std::string battle(const T& combatant1, const T& combatant2) = 0;
};

#endif IBATTLE_SIMULATOR_H
