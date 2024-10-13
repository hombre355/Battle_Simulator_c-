#ifndef ITRANSFORMER_H
#define ITRANSFORMER_H


#include <string>

class ITransformer 
{
public:
    virtual ~ITransformer() = default;

    virtual std::string getName() const = 0;
    virtual std::string getFaction() const = 0;
    virtual int getStrength() const = 0;
    virtual int getWins() const = 0;
    virtual int getLosses() const = 0;

    virtual void winBattle() = 0;
    virtual void loseBattle() = 0;
};
#endif // !ITRANSFORMER_H