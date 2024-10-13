#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "ITransformer.h"
#include <string>

class Transformer : public ITransformer
{
private:
    std::string name;
    std::string faction;
    int strength;
    int wins;
    int losses;

public:
    Transformer(const std::string& name, const std::string& faction, int strength)
        : name(name), faction(faction), strength(strength), wins(0), losses(0) {}

    std::string getName() const override { return name; }
    std::string getFaction() const override { return faction; }
    int getStrength() const override { return strength; }
    int getWins() const override { return wins; }
    int getLosses() const override { return losses; }

    void winBattle() override { wins++; }
    void loseBattle() override { losses++; }
};

#endif TRANSFORMER_H