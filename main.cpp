#include "hanoi.h"
#include "pow.h"
#include <iostream>

int main(int argc, char* argv[]) {
    double base = (argc == 2) ? std::stod(argv[1]) : 2.0;
    std::cout << Pow<-4>{}(base) << '\n';

    Hanoi<3, 1, 3>{}();

    return 0;
}