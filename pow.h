#ifndef TEMPLATE_METAPROGRAMMING_POW_H
#define TEMPLATE_METAPROGRAMMING_POW_H

#include <type_traits>

template<int Exp, typename Enable = void>
struct Pow {
    double operator()(double base) const {
        Pow<Exp / 2> p;
        return (Exp & 1) ? base * p(base) * p(base) : p(base) * p(base);
    }
};

template <int Exp>
struct Pow<Exp, typename std::enable_if<Exp < 0>::type> {
    double operator()(double base) const {
        return 1.0 / Pow<-Exp>{}(base);
    }
};

template<>
struct Pow<1> {
    double operator()(double base) const {
        return base;
    }
};

template<>
struct Pow<0> {
    double operator()([[maybe_unused]] double base) const {
        return 1.0;
    }
};

#endif