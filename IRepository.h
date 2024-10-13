#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <vector>
#include "ITransformer.h"

template <typename T>
class IRepository 
{
public:
    virtual ~IRepository() = default;

    virtual int add(const T& item) = 0;
    virtual int remove(const std::string& name) = 0;
    virtual T* get(const std::string& name) = 0;
    virtual std::vector<T> getAll() const = 0;
};

#endif // !IREPOSITORY_H