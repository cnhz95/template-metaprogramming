#include "hanoi.h"
#include "pow.h"
#include <iostream>

int main() {
    std::cout << Pow<-4>{}(2) << '\n';

    Hanoi<3, 1, 3>{}();

    return 0;
}