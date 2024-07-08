#ifndef PILLAR_H
#define PILLAR_H

#include <cstddef>
#include <string>
#include <vector>

using plate_size_t = int;

class Pillar
{
public:
    Pillar(std::string name);
    Pillar(std::string name, std::size_t num);

public:
    void move_to(Pillar &other);
    std::size_t size() const;
    plate_size_t operator[](std::size_t index) const;
    std::string get_name() const;

private:
    std::string mem_name;
    std::vector<plate_size_t> mem_store;
};


#endif//PILLAR_H