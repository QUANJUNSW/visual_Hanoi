#include <iostream>

#include "Hanoi.h"

using namespace std;

int main()
{
    Hanoi h(4);

    h(Hanoi::LaunchMode::RECURSION);
}