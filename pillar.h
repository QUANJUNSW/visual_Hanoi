#ifndef PILLAR_H
#define PILLAR_H

#include <cstddef>
#include <vector>
#include <string>

using value_t = int;

class Pillar
{
public:
    Pillar(std::string name);
    Pillar(std::string name,std::size_t num);

public:
    void push(value_t value);
    value_t pop();
    std::size_t size() const;
    value_t operator[](std::size_t index) const;
    std::string get_name() const;

private:
    std::string name;
    std::vector<value_t> store;
};


#endif//PILLAR_H