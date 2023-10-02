#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Fraction.hpp"

using namespace std;

struct My_functor
{
	const Fraction comparison_value;
	My_functor(const Fraction &f) : comparison_value(f) {}
	bool operator()(const Fraction &f)
	{
		return f < comparison_value;
	}
};


bool My_function(const Fraction &f)
{
	return f < Fraction(0, 1);
}


void delete_negative(vector<Fraction> &vec)
{
	const Fraction zero(0, 1);

	// vec.erase(remove_if(vec.begin(), vec.end(),
	// 					[&zero](const Fraction &f)
	// 					{ return f < zero; }),
	// 		  vec.end());
	auto begin = remove_if(vec.begin(), vec.end(), [&zero](const Fraction &f)
						   { return f < zero; });
	// auto begin = remove_if(vec.begin(), vec.end(), My_functor(zero));
	// auto begin = remove_if(vec.begin(), vec.end(), My_function);
	vec.erase(begin, vec.end());
}

int main()
{
	ifstream my_file("fraction.txt");
	vector<Fraction> vec;
	if (my_file.is_open())
	{
		Fraction my_fraction;
		while (my_file >> my_fraction)
		{
			vec.push_back(my_fraction);
		}
	}
	else
	{
		cout << "Cannot open fraction.txt" << endl;
	}
	my_file.close();
	for (auto v = vec.begin(); v != vec.end(); ++v)
	{
		cout << *v << endl;
	}

	cout << endl;

	delete_negative(vec);

	for (auto &v : vec)
	{
		cout << v << endl;
	}
	return 0;
}
