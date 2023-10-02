#include "Fraction.hpp"
#include <iostream>
using namespace std;

Fraction::Fraction() : num_(0), den_(1) {}

Fraction::Fraction(const int &num, const int &den)
{
    if (den != 0)
    {
        this->num_ = num;
        this->den_ = den;
    }
    else
    {
        std::cout << "Error denumerator == 0" << std::endl;
    }
}

Fraction::Fraction(const Fraction &fraction){
    this->num_ = fraction.num_;
    this->den_ = fraction.den_;
}


Fraction Fraction::operator+(const Fraction &fraction)
{
    return Fraction(num_ * fraction.get_den() + fraction.get_num() * den_, den_ * fraction.get_den());
}

bool Fraction::operator==(const Fraction &fraction) const
{
    return (this->num_ * fraction.get_den() == this->den_ * fraction.get_num());
}

bool Fraction::operator<(const Fraction &fraction) const
{
    return (this->num_ * fraction.get_den() < this->den_ * fraction.get_num());
}

ostream &operator<<(ostream &os, const Fraction &fraction)
{
    os << "numerator = " << fraction.num_ << " denumerator = " << fraction.den_;
    return os;
}

istream &operator>>(istream &os, Fraction &fraction)
{
    os >> fraction.num_ >> fraction.den_;
    return os;
}
