#ifndef HANOI_H
#define HANOI_H

#include <cstddef>

#include "pillar.h"


class Hanoi
{
public:
    enum class LaunchMode
    {
        RECURSION,
        CIRCULATION
    };

public:
    Hanoi(std::size_t num);

public:
    void print() const;
    void operator()(LaunchMode mode);

private:
    void recursion(std::size_t n, Pillar &A, Pillar &B, Pillar &C);
    void circulation();

private:
    std::size_t record;
    Pillar src;
    Pillar assist;
    Pillar dest;
};


#endif//HANOI_H