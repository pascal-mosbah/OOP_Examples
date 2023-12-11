#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

void Exercice_2_a(const int &n)
{
    srand((unsigned int)time(NULL));
    int *tab;

    try //hors sujet mais relevant
    {
        tab = new int[n];
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << e.what();
    }

    for (int i = 0; i < n; ++i)
    {
        tab[i] = rand();
    }
    std::sort(tab, tab + n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    delete[] tab;
}

class Polynome
{
private:
    std::vector<float> polynome_;

public:
    Polynome(){};
    Polynome(const Polynome &poly);
    int max_degre();
    float get_val(const float &val);
    void ajouter_un_monome(const int &degree, const float &coeff);
    friend std::ostream &operator<<(std::ostream &os, const Polynome &poly);
    friend std::istream &operator>>(std::istream &os, const Polynome &poly);
    float operator()(const float &val);
    Polynome operator+(const Polynome &other);
    Polynome operator*(const Polynome &other);
};

int Polynome::max_degre()
{
    return static_cast<int>(polynome_.size() - 1);
}

void Polynome::ajouter_un_monome(const int &degree, const float &coeff)
{
    if (polynome_.size() == 0 || degree > polynome_.size() - 1)
    {
        polynome_.resize(degree + 1, 0);
        polynome_[degree] = coeff;
    }
    else
    {
        polynome_[degree] += coeff;
    }
}

float Polynome::operator()(const float &val)
{
    float sum = 0;
    for (float i = 0; auto const &mon : this->polynome_)
    {
        sum += mon * powf(val, i++);
    }
    return sum;
}

Polynome Polynome::operator+(const Polynome &other)
{
    Polynome poly(*this);
    for (int i = 0; auto const &mon : other.polynome_)
    {
        poly.ajouter_un_monome(i++, mon);
    }
    return poly;
}

Polynome Polynome::operator*(const Polynome &other)
{
    Polynome poly;
    for (int i = 0; auto const &mon_i : this->polynome_)
    {
        for (int j = 0; auto const &mon_j : other.polynome_)
        {
            poly.ajouter_un_monome(i + j++, mon_i * mon_j);
        }
        ++i;
    }
    return poly;
}

Polynome::Polynome(const Polynome &poly) : polynome_(poly.polynome_) {}

std::istream &operator>>(std::istream &is, Polynome &poly)
{
    float coeff;
    int i = 0;
    while (is >> coeff)
    {
        poly.ajouter_un_monome(i++, coeff);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Polynome &poly)
{
    int i = static_cast<int>(poly.polynome_.size() - 1);
    for (auto mono = poly.polynome_.rbegin(); mono != poly.polynome_.rend(); ++mono)
    {
        if (*mono != 0)
        {
            if (*mono > 0 && i != poly.polynome_.size() - 1)
            {
                std::cout << "+";
            }
            std::cout << *mono;
            if (i > 0)
            {
                std::cout << "X";
                if (i > 1)
                {
                    std::cout << "^" << i;
                }
            }
        }
        --i;
    }
    return os;
}

int main()
{
    std::cout << "Exercice 2-a" << std::endl;
    Exercice_2_a(10);
    std::cout << std::endl;

    Polynome poly1, poly2;
    poly1.ajouter_un_monome(2, 5);
    poly1.ajouter_un_monome(1, 4);
    std::cout << "max degre poly1 :" << poly1.max_degre() << std::endl;
    std::cout << "poly1 : " << poly1 << std::endl;
    poly1.ajouter_un_monome(1, 2);
    std::cout << "poly1 après \"ajouter_un_monome(1, 2)\" : " << poly1 << std::endl;

    std::cout << "poly1(2) :" << poly1(2) << std::endl;

    poly2.ajouter_un_monome(5, 5);
    poly2.ajouter_un_monome(0, 4);
    std::cout << "max degre poly2 :" << poly2.max_degre() << std::endl;
    std::cout << "poly2 : " << poly2 << std::endl;

    auto poly3 = poly1 + poly2;
    std::cout << "max degre (poly1 + poly2) :" << poly3.max_degre() << std::endl;
    std::cout << "poly3 (poly1 + poly2) : " << poly3 << std::endl;

    auto poly4 = poly1 * poly2;
    std::cout << "max degre (poly1 * poly2) :" << poly4.max_degre() << std::endl;
    std::cout << "poly4 (poly1 * poly2) : " << poly4 << std::endl;

    std::ifstream file("test.txt");
    if (file.is_open())
    {
        Polynome poly5;
        file >> poly5;
        std::cout << "poly5 : " << poly5 << std::endl;
    }
    return 0;
}