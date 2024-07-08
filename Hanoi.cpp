#include "Hanoi.h"
#include <iostream>
#include <string>

using std::cout, std::cerr, std ::endl;

Hanoi::Hanoi(const std::size_t plate_num)
: mem_src("src", plate_num), mem_assist("assist"), mem_dest("dest"), mem_plate_num(plate_num)
{
}

void Hanoi::print() const
{
    Painter::paint(mem_plate_num, mem_src, mem_assist, mem_dest);
}

void Hanoi::operator()(const LaunchMode mode)
{
    if (mode == LaunchMode::RECURSION)
    {
        recursion(mem_plate_num, mem_src, mem_assist, mem_dest);
    }
    else if (mode == LaunchMode::CIRCULATION)
    {
        circulation();
    }
    else
    {
        cerr << "No thar mode" << endl;
    }
}

void Hanoi::recursion(const std::size_t plate_num, Pillar &A, Pillar &B, Pillar &C)
{
    if (plate_num == 1)
    {
        A.move_to(C);
        print();
        cout << A.get_name() << " -> " << C.get_name() << endl;
    }
    else
    {
        recursion(plate_num - 1, A, C, B);
        A.move_to(C);
        print();
        cout << A.get_name() << " -> " << C.get_name() << endl;
        recursion(plate_num - 1, B, A, C);
    }
}

void Hanoi::circulation()
{
}
