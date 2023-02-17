#ifndef TEMPLATE_METAPROGRAMMING_POW_H
#define TEMPLATE_METAPROGRAMMING_POW_H

template<typename Exp>
struct Base {

};

template<int Exp>
struct Pow : Base<int> {
    double operator()(double base) const {
        Pow<Exp / 2> p;
        return (Exp & 1) ? base * p(base) * p(base) : p(base) * p(base);
    }
};

template<>
struct Pow<1> {
    double operator()(double base) {
        return base;
    }
};

template<>
struct Pow<0> {
    double operator()([[maybe_unused]] double base) {
        return 1.0;
    }
};

#endif