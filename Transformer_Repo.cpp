#include "Transformer_Repo.h"
#include <string>
#include <vector>
#include <algorithm>


int Transformer_Repository::add(const Transformer& transformer)
{
    std::string a = transformer.getName();

    auto it = std::find_if(transformers.begin(), transformers.end(),
        [&a](const Transformer& t) { return t.getName() == a; });

    if(it != transformers.end())
    {
        transformers.push_back(transformer);
        return 0;
    }
    else
    {

        return 1;
    }
    return 0;
    
}

int Transformer_Repository::remove(const std::string& name)
{
    auto it = std::remove_if(transformers.begin(), transformers.end(),
        [&name](const Transformer& t) { return t.getName() == name; });

    if (it != transformers.end())
    {
        transformers.erase(it, transformers.end());
    }
    return 0;
}

Transformer* Transformer_Repository::get(const std::string& name)
{
    for (auto& transformer : transformers)
    {
        if (transformer.getName() == name)
        {
            return &transformer;
        }
    }
    return nullptr;
}

std::vector<Transformer> Transformer_Repository::getAll() const
{
    return transformers;
}