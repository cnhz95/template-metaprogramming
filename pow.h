#ifndef TEMPLATE_METAPROGRAMMING_POW_H
#define TEMPLATE_METAPROGRAMMING_POW_H

#include <type_traits>

// Den mest generella, 2 parametrar
template<int Exp, typename Enable = void>
struct Pow {
    constexpr double operator()(const double base) const {
        Pow<Exp / 2> p;
        return Exp & 1 ? base * p(base) * p(base) : p(base) * p(base);
    }
};

// Specialisering med 1 parameter
template <int Exp>
struct Pow<Exp, typename std::enable_if<Exp < 0>::type> {
    constexpr double operator()(const double base) const {
        return 1.0 / Pow<-Exp>{}(base);
    }
};

// Specialisering med 0 parametrar
template<>
struct Pow<1> {
    constexpr double operator()(const double base) const {
        return base;
    }
};

// Specialisering med 0 parametrar
template<>
struct Pow<0> {
    constexpr double operator()([[maybe_unused]] double base) const {
        return 1.0;
    }
};

#endif