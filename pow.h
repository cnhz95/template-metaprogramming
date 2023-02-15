#ifndef TEMPLATE_METAPROGRAMMING_POW_H
#define TEMPLATE_METAPROGRAMMING_POW_H

template<typename Exp>
struct Base {

};

template<int Exp>
struct Pow : Base<int> {
    double operator()(double base) const {
        return base * Pow<Exp - 1>{}(base);
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