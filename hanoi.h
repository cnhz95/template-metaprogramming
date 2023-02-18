#ifndef TEMPLATE_METAPROGRAMMING_HANOI_H
#define TEMPLATE_METAPROGRAMMING_HANOI_H

#include <iostream>

template<int N, int Start, int End>
struct Hanoi {
    void operator()() const {
        constexpr int other = 6 - Start - End;
        Hanoi<N - 1, Start, other>{}();
        std::cout << "Move disk " << N << " from " << Start << " to " << End << "\n";
        Hanoi<N - 1, other, End>{}();
    }
};

template<int Start, int End>
struct Hanoi<1, Start, End> {
    void operator()() const {
        std::cout << "Move disk 1 from " << Start << " to " << End << "\n";
    }
};

#endif