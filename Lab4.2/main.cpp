#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define STRING_SIZE 256

/*
	Write a program that is all
	digits contained in
	entered line, replaces them
	squares and displays on
	screen again
*/

int main()
{
	char string[STRING_SIZE];
	char result_string[STRING_SIZE];
	int j = 0;
	int k = 0;
	int num;
	int flipped_num = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter sentence: ");
	fgets(string, STRING_SIZE, stdin);

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] > 48 && string[i] < 58)
		{
			num = string[i] - 48;
			num *= num;

			while (num)
			{
				flipped_num = flipped_num * 10 + num % 10;
				num /= 10;
			}

			while (flipped_num > 0)
			{
				result_string[j] = (flipped_num % 10) + 48;
				flipped_num /= 10;
				j++;
			}
		}
		else
		{
			result_string[j] = string[i];
			j++;
		}
	}

	result_string[++j] = '\n';

	do
	{
		printf("%c", result_string[k]);
		k++;
	} while (result_string[k] != '\n');

	return 0;
}