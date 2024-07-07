#include "Hanoi.h"
#include <iostream>
#include <string>

using std::cout, std::cerr, std ::endl;

Hanoi::Hanoi(std::size_t num)
: src("src", num), assist("assist"), dest("dest"), record(num)
{
}

void Hanoi::print() const
{
    auto print_space = [this](value_t value)
    {
        std::size_t space_num = this->record - (value - 1) / 2;

        for (int i = 0; i < space_num; i++)
        {
            cout << ' ';
        }
    };

    auto print_pillar_line = [this, print_space](std::size_t index, const Pillar &pillar)
    {
        value_t temp = pillar[index - 1];

        print_space(temp);

        for (int i = 0; i < temp; i++)
        {
            cout << "+";
        }
        print_space(temp);
    };

    auto print_space_line = [this]()
    {
        std::string str(2 * this->record + 1, ' ');
        cout << str;
    };

    cout << endl;
    for (int i = record; i > 0; --i)
    {
        cout << i << " | ";
        if (src.size() >= i)
        {
            print_pillar_line(i, src);
        }
        else
        {
            print_space_line();
        }

        if (assist.size() >= i)
        {
            print_pillar_line(i, assist);
        }
        else
        {
            print_space_line();
        }

        if (dest.size() >= i)
        {
            print_pillar_line(i, dest);
        }
        else
        {
            print_space_line();
        }
        cout << endl;
    }
}

void Hanoi::operator()(LaunchMode mode)
{
    if (mode == LaunchMode::RECURSION)
    {
        recursion(record, src, assist, dest);
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

void Hanoi::recursion(std::size_t n, Pillar &A, Pillar &B, Pillar &C)
{
    if (n == 1)
    {
        C.push(A.pop());
        print();
        cout << A.get_name() << " -> " << C.get_name() << endl;
    }
    else
    {
        recursion(n - 1, A, C, B);
        C.push(A.pop());
        print();
        cout << A.get_name() << " -> " << C.get_name() << endl;
        recursion(n - 1, B, A, C);
    }
}

void Hanoi::circulation()
{
    
}
