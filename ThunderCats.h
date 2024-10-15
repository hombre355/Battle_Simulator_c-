#ifndef THUNDERCATS_H
#define THUNDERCATS_H

#include "ICombatant.h"
#include <string>

class ThunderCats : public ICombatant
{
private:
    std::string name;
    std::string faction;
    int strength;
    int wins;
    int losses;
    
    std::string weapon;

public:
    ThunderCats(const std::string& name, const std::string& faction, int strength, const std::string& weapon)
        : name(name), faction(faction), strength(strength), weapon(weapon), wins(0), losses(0) {}

    std::string getName() const override { return name; }
    std::string getFaction() const override { return faction; }
    int getStrength() const override { return strength; }
    int getWins() const override { return wins; }
    int getLosses() const override { return losses; }

    std::string getWeapon() const { return weapon; }

    void winBattle() override { wins++; }
    void loseBattle() override { losses++; }
};

#endif THUNDERCATS_H