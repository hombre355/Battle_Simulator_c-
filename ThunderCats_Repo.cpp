#include "ThunderCats_Repo.h"
#include <string>
#include <vector>
#include <algorithm>


int ThunderCats_Repository::add(const ThunderCats& t1)
{
    std::string name = t1.getName();

    auto name_it = std::find_if(ThunderCats_Vec.begin(), ThunderCats_Vec.end(),
        [&name](const ThunderCats& t) { return t.getName() == name; });

    if (name_it == ThunderCats_Vec.end())
    {
        ThunderCats_Vec.push_back(t1);
        return 0;
    }
    else
    {
        std::string faction = t1.getFaction();

        auto faction_it = std::find_if(ThunderCats_Vec.begin(), ThunderCats_Vec.end(),
            [&faction](const ThunderCats& t) { return t.getFaction() == faction; });

        if (faction_it == ThunderCats_Vec.end())
        {
            ThunderCats_Vec.push_back(t1);
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void ThunderCats_Repository::remove(int index)
{
    ThunderCats_Vec.erase(ThunderCats_Vec.begin() + index);
}


ThunderCats* ThunderCats_Repository::get(int index)
{
    return &ThunderCats_Vec.at(index);
}


std::vector<ThunderCats> ThunderCats_Repository::getAll() const
{
    return ThunderCats_Vec;
}