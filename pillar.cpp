#include "pillar.h"


Pillar::Pillar(std::string name)
: name(name)
{
}

Pillar::Pillar(std::string name, std::size_t num)
: store(), name(name)
{
    for (value_t i = num - 1; i >= 0; --i)
    {
        store.push_back(2 * i + 1);
    }
}

void Pillar::push(value_t value)
{
    store.push_back(value);
}

value_t Pillar::pop()
{
    value_t result = store.back();

    store.pop_back();

    return result;
}

std::size_t Pillar::size() const
{
    return store.size();
}

value_t Pillar::operator[](std::size_t index) const
{
    return store[index];
}

std::string Pillar::get_name() const
{
    return name;
}
