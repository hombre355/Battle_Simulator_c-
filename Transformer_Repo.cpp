#include "Transformer_Repo.h"
#include <string>
#include <vector>
#include <algorithm>


int Transformer_Repository::add(const Transformer& transformer)
{
    std::string name = transformer.getName();

    auto name_it = std::find_if(transformers_vec.begin(), transformers_vec.end(),
        [&name](const Transformer& t) { return t.getName() == name; });

    if (name_it == transformers_vec.end())
    {
        transformers_vec.push_back(transformer);
        return 0;
    }
    else
    {
        std::string faction = transformer.getFaction();

        auto faction_it = std::find_if(transformers_vec.begin(), transformers_vec.end(),
            [&faction](const Transformer& t) { return t.getFaction() == faction; });

        if (faction_it == transformers_vec.end())
        {
            transformers_vec.push_back(transformer);
            return 0;
        }
        else
        {
            return 1;
        }
    }
}


void Transformer_Repository::remove(int index)
{
    transformers_vec.erase(transformers_vec.begin() + index);
}


Transformer* Transformer_Repository::get(int index)
{
    return &transformers_vec.at(index);
}


std::vector<Transformer> Transformer_Repository::getAll() const
{
    return transformers_vec;
}