#include <iostream>
using namespace std;

class Fraction
{
private:
    int num_ = 0, den_ = 1;

public:
    Fraction();
    Fraction(const Fraction &Fraction);// = default;
    Fraction(const int &num, const int &den);
    void set_num(const int &num);
    void set_den(const int &deno);
    int get_num() const { return num_; };
    int get_den() const { return den_; };

    Fraction operator+(const Fraction &Fraction);
    bool operator==(const Fraction &Fraction) const;
    bool operator<(const Fraction &Fraction) const;

    friend ostream &operator<<(ostream &os, const Fraction &Fraction);
    friend istream &operator>>(istream &os, Fraction &Fraction);
};
