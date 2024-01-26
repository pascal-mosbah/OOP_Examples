#include <random>
#include <map>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <complex>
#include <thread>
#include <string>

struct comp_functor
{
    bool operator()(const int &v1, const int &v2)
    {
        return v1 > v2;
    }
} comp_functor;

bool comp_function(const int &v1, const int &v2)
{
    return v1 > v2;
}

template <typename _Type>
struct Monomial
{
    size_t expo_;
    _Type coeff_;
};

template <typename _Type>
class My_polynomial
{
private:
    std::vector<_Type> monomial_;

public:
    size_t get_size(); // retourne la taille du vecteur monomial_

    My_polynomial();                                  // Constructeur 1
    My_polynomial(const My_polynomial<_Type> &other); // Constructeur 2
    My_polynomial(My_polynomial<_Type> &&other);      // Constructeur 3

    _Type &operator[](const size_t &ind); // retourne une référence sur le ième élément de vec_

    _Type operator()(const _Type &val); // retourne la valeur du polynôme pour la valeur x = val

    My_polynomial<_Type> operator+(const My_polynomial<_Type> &p); // Addition de deux polynômes de type « _Type »
    My_polynomial<_Type> operator*(const My_polynomial<_Type> &p); // Multiplication de deux polynômes de type « _Type »

    My_polynomial<_Type> &operator+=(const Monomial<_Type> &m); // Addition d'un monôme et un polynôme

    template <typename _Typel>
    friend std::ostream &operator<<(std::ostream &is, const My_polynomial<_Typel> &p); // Surcharge de l'opérateur <<

    template <typename _Typel>
    friend Monomial<_Typel> operator>>(Monomial<_Typel> &is, My_polynomial<_Typel> &p); // Surcharge de l'opérateur >> attention il s'agit ici d'un monôme et pas de la classe std::istream
};

template <typename _Type>
size_t My_polynomial<_Type>::get_size()
{
    return monomial_.size();
}

template <typename _Type>
My_polynomial<_Type>::My_polynomial()
{
}

template <typename _Type>
My_polynomial<_Type>::My_polynomial(const My_polynomial<_Type> &other)
{
    monomial_ = other.monomial_;
}

template <typename _Type>
My_polynomial<_Type>::My_polynomial(My_polynomial<_Type> &&other)
{
    monomial_ = other.monomial_;
}

template <typename _Type>
My_polynomial<_Type> &My_polynomial<_Type>::operator+=(const Monomial<_Type> &m)
{
    auto ind = m.expo_;
    auto coeff = m.coeff_;
    if (ind >= this->get_size())
    {
        this->monomial_.resize(ind + 1);
    }
    this->monomial_[ind] += coeff;
    return *this;
}

template <typename _Type>
_Type My_polynomial<_Type>::operator()(const _Type &val)
{
    _Type result = 0;
    for (std::size_t count = 0; const auto &p : this->monomial_)
    {
        result += p * pow(val, count);
        ++count;
    }
    return result;
}

template <typename _Type>
_Type &My_polynomial<_Type>::operator[](const size_t &ind)
{
    if (ind >= monomial_.size())
    {
        monomial_.resize(ind + 1);
    }
    return monomial_[ind];
}

template <typename _Type>
My_polynomial<_Type> My_polynomial<_Type>::operator+(const My_polynomial<_Type> &p)
{
    My_polynomial<_Type> poly(p);

    for (std::size_t count = 0; const auto &p : this->monomial_)
    {
        poly += Monomial<_Type>(count++, p);
    }
    return poly;
}

template <typename _Type>
My_polynomial<_Type> My_polynomial<_Type>::operator*(const My_polynomial<_Type> &p)
{
    My_polynomial<_Type> poly;

    for (std::size_t count_p = 0; const auto &p : p.monomial_)
    {
        for (std::size_t count_q = 0; const auto &q : this->monomial_)
        {
            poly += Monomial<_Type>(count_p + count_q, p * q);
            ++count_q;
        }
        ++count_p;
    }
    return poly;
}

template <typename _Type>
std::ostream &operator<<(std::ostream &os, const My_polynomial<_Type> &p)
{
    for (std::size_t count_p = 0; const auto &p : p.monomial_)
    {
        os << " +" << p << " X^" << count_p++;
    }
    return os;
}

template <typename _Type>
Monomial<_Type> operator>>(Monomial<_Type> &is, My_polynomial<_Type> &p)
{
    p += is;
    return is;
}

int main()
{
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(-100, 100); //(min, max)
    std::vector<int> v;
    v.reserve(100);
    auto comp_lambda = [](const int &a, const int &b)
    { return a > b; };
    for (int i = 0; i < 100; ++i)
    {
        v.push_back(dist(rng)); // génération alléatoire de valeurs
    }
    std::sort(v.begin(), v.end(), comp_lambda);
    std::sort(v.begin(), v.end(), comp_functor);
    std::sort(v.begin(), v.end(), comp_function);

    std::cout << "--------------------------------------------------------" << std::endl;
    My_polynomial<std::complex<float>> poly1;

    // for (size_t i = 0; i < 5; ++i)
    // {
    //     Monomial<std::complex<float>> m(i, {static_cast<float>(i), static_cast<float>(i + 1)});
    //     poly1 += m;
    // }

    // std::cout << "poly1 =" << poly1 << std::endl;
    // std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    My_polynomial<float> poly2;

    for (size_t i = 0; i < 3; ++i)
    {
        Monomial<float> m(i, static_cast<float>(i + 1));
        poly2 += m;
    }

    std::cout << "poly2 =" << poly2 << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    My_polynomial<float> poly3;

    for (size_t i = 0; i < 3; ++i)
    {
        Monomial<float> m(i, static_cast<float>(i + 2));
        poly3 += m;
    }

    std::cout << "poly3 =" << poly3 << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    auto poly4 = poly2 + poly3;

    std::cout << "poly4 =" << poly4 << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    auto poly5 = poly2 * poly3;

    std::cout << "poly5 =" << poly5 << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "poly3(2) = " << poly3(2) << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "indice n°2 of poly3 = " << poly3[2] << std::endl;
    poly3[5] = 15;
    std::cout << "indice n°5 of poly3 = " << poly3[5] << std::endl;

    std::cout << "poly3 =" << poly3 << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << "--------------------------------------------------------" << std::endl;
    My_polynomial<float> poly6;
    std::cout << "poly6 =" << poly6 << std::endl;

    Monomial<float> m0(0, 1);
    m0 >> poly6;
    Monomial<float> m1(1, 2);
    m1 >> poly6;
    Monomial<float> m5(3, 4);
    m5 >> poly6;

    std::cout << "poly6 =" << poly6 << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    return EXIT_SUCCESS;
}
