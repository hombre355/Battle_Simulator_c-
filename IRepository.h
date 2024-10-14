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
    virtual void remove(int index) = 0;
    virtual T* get(int index) = 0;
    virtual std::vector<T> getAll() const = 0;
};

#endif // !IREPOSITORY_H