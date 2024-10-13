#ifndef TRANSFORMER_REPO_H
#define TRANSFORMER_REPO_H

#include "IRepository.h"
#include "Transformer.h"

class Transformer_Repository : public IRepository<Transformer>
{
private:
    std::vector<Transformer> transformers;

public:
    int add(const Transformer& transformer) override;
    int remove(const std::string& name) override;
    Transformer* get(const std::string& name) override;
    std::vector<Transformer> getAll() const override;
};

#endif TRANSFORMER_REPO_H