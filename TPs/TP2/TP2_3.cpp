#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cstring>

int main()
{
	std::ifstream my_file("../../TP2_3.cpp");
	if (!my_file.is_open())
	{
		std::cout << "The file TP2_3.cpp could not be opened" << std::endl;
		return EXIT_FAILURE;
	}
	constexpr int size = (1 << (sizeof(char) * 8)) - 1;
	unsigned my_caracters[size] = {0};

	// C++ map
	// std::map<char, int> my_count;

	std::string line;
	size_t number_of_characters = 0, number_of_words = 0, number_of_lines = 0;
	while (std::getline(my_file, line))
	{
		++number_of_lines;
		std::string word;
		std::stringstream ss(line);
		while (ss >> word)
		{
			++number_of_words;
			number_of_characters += word.size();
			for (auto icar : word)
			{
				// C++ map
				//			++my_count[std::tolower(icar)];
				++my_caracters[std::tolower(icar)];
			}
		}
	}

	std::cout << "number of lines " << number_of_lines << std::endl;
	std::cout << "number of words " << number_of_words << std::endl;
	std::cout << "number of characters " << number_of_characters << std::endl;

	// C++ map
	/* 	for (auto inum : my_count) {
			std::cout << inum.first << " " << inum.second << std::endl;
		}
	 */
	for (unsigned char c = 0; c < size; ++c)
	{
		if (my_caracters[c])
		{
			std::cout << c << " " << my_caracters[c] << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
