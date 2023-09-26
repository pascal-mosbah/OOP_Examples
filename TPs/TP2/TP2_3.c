#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

int main()
{
	FILE *my_file = fopen("../../TP2_3.c", "r");

	if (!my_file)
	{
		printf("The file ../../TP2_3.c could not be opened\n");
		return EXIT_FAILURE;
	}

	 char my_caracters[UCHAR_MAX] = {0};

	char line[1000];

	size_t number_of_characters = 0, number_of_words = 0, number_of_lines = 0;

	while (fgets(line, 1000, my_file) != NULL)
	{
		++number_of_lines;
		char *word = strtok(line, " ");

		// loop through the string to extract all other tokens
		while (word != NULL)
		{
			++number_of_words;
			number_of_characters += strlen(word);
			for (int i = 0; i < strlen(word); ++i)
			{
				++my_caracters[tolower(word[i])];
			}
			word = strtok(NULL, " ");
		}
	}

#ifdef _WIN32
	printf("number of lines %llu\n", number_of_lines);
	printf("number of words %llu\n", number_of_words);
	printf("number of characters %llu\n", number_of_characters);
#else
	printf("number of lines %lu\n", number_of_lines);
	printf("number of words %lu\n", number_of_words);
	printf("number of characters %lu\n", number_of_characters);
#endif

	for (unsigned char c = 0; c < UCHAR_MAX; ++c)
	{
		if (my_caracters[c]&&isprint(c))
		{
			printf("%c %u\n", c, my_caracters[c]);
		}
	}
	return EXIT_SUCCESS;
}
