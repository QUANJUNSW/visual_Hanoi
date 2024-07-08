#include "pillar.h"


Pillar::Pillar(std::string name)
: mem_name(name)
{
}

Pillar::Pillar(std::string name, std::size_t num)
: mem_store(), mem_name(name)
{
    for (plate_size_t i = num; i > 0; --i)
    {
        mem_store.push_back(i);
    }
}

void Pillar::move_to(Pillar &other)
{
    other.mem_store.push_back(this->mem_store.back());
    this->mem_store.pop_back();
}

std::size_t Pillar::size() const
{
    return mem_store.size();
}

plate_size_t Pillar::operator[](std::size_t index) const
{
    return mem_store[index];
}

std::string Pillar::get_name() const
{
    return mem_name;
}
