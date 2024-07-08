#ifndef HANOI_H
#define HANOI_H

#include <cstddef>

#include "painter.h"
#include "pillar.h"


class Hanoi
{
public:
    using Painter = CMDPainter;

public:
    enum class LaunchMode
    {
        RECURSION,
        CIRCULATION
    };

public:
    Hanoi(const std::size_t plate_num);

public:
    void print() const;
    void operator()(const LaunchMode mode);

private:
    void recursion(const std::size_t plate_num, Pillar &A, Pillar &B, Pillar &C);
    void circulation();

private:
    const std::size_t mem_plate_num;
    Pillar mem_src;
    Pillar mem_assist;
    Pillar mem_dest;
};


#endif//HANOI_H