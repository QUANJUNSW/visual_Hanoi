#ifndef PAINTER_H
#define PAINTER_H

#include "pillar.h"
#include <cstddef>

class CMDPainter
{
public:
    static void paint(const std::size_t plate_num, const Pillar &src, const Pillar &assist, const Pillar &dest);

private:
    static void print_space(std::size_t num);
    static void print_single_pillar(const std::size_t plate_num, const std::size_t level, const Pillar &pillar);
};

#endif//PAINTER_H