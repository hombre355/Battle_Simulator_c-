#ifndef TRANSFORMER_REPO_H
#define TRANSFORMER_REPO_H

#include "IRepository.h"
#include "Transformer.h"

class Transformer_Repository : public IRepository<Transformer>
{
private:
    std::vector<Transformer> transformers;

public:

    /**************************************************************
    * 
    * This function overrides the virtual function that will 
    * add a transformer object to a vector of transformer objects.
    * It first checks the vector to see if there is an object 
    * that has the same name and faction. If there is match, then 
    * return 1. If there is no match then add it to the vector and 
    * return 0.
    * 
    ***************************************************************/
    int add(const Transformer& transformer) override;

    /**********************************************************
    *
    * This function overrides the virtual function that will
    * remove the object from the vector.
    *
    ***********************************************************/
    void remove(int index) override;

    /**********************************************************
    *
    * This function overrides the virtual function that will
    * return the object from the given index.
    *
    ***********************************************************/
    Transformer* get(int index) override;

    /**********************************************************
    *
    * This function overrides the virtual function that will
    * return all the objects from the vector.
    *
    ***********************************************************/
    std::vector<Transformer> getAll() const override;
};

#endif TRANSFORMER_REPO_H