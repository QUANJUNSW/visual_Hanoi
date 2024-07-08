#include "painter.h"

#include <iostream>

using std::cout, std::endl;


void CMDPainter::paint(const std::size_t plate_num, const Pillar &src, const Pillar &assist, const Pillar &dest)
{
    cout << endl;
    for (int i = plate_num; i > 0; --i)
    {
        cout << i << " | ";

        print_single_pillar(plate_num, i, src);
        print_single_pillar(plate_num, i, assist);
        print_single_pillar(plate_num, i, dest);

        cout << endl;
    }

    for (int i = 0; i < 3 * (plate_num * 2 - 1) + 4; ++i)
    {
        cout << '-';
    }

    cout << endl;
}

void CMDPainter::print_space(std::size_t num)
{
    for (int i = 0; i < num; ++i)
    {
        cout << ' ';
    }
}

void CMDPainter::print_single_pillar(const std::size_t plate_num, const std::size_t level, const Pillar &pillar)
{
    if (pillar.size() >= level)
    {
        const plate_size_t plate_size = pillar[level - 1];

        print_space(plate_num - plate_size);

        for (int i = 0; i < 2 * plate_size - 1; ++i)
        {
            cout << '+';
        }

        print_space(plate_num - plate_size);
    }
    else
    {
        print_space(2 * plate_num - 1);
    }
}
