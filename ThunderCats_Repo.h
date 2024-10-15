#ifndef THUNDERCATS_REPO_H
#define THUNDERCATS_REPO_H

#include "IRepository.h"
#include "ThunderCats.h"

class ThunderCats_Repository : public IRepository<ThunderCats>
{
private:
    std::vector<ThunderCats> ThunderCats_Vec;

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
    int add(const ThunderCats& transformer) override;

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
    ThunderCats* get(int index) override;

    /**********************************************************
    *
    * This function overrides the virtual function that will
    * return all the objects from the vector.
    *
    ***********************************************************/
    std::vector<ThunderCats> getAll() const override;
};

#endif THUNDERCATS_REPO_H