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
	A sentence is given. Print
	from him all the words before
	which directly
	is the letter ch in
	in one word. The letter ch
	is entered from the keyboard
*/

int main()
{
	char string[STRING_SIZE];
	char letter;
	short int check = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter sentence: ");
	fgets(string, STRING_SIZE, stdin);

	printf("Enter letter: ");
	scanf("%c", &letter);

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == letter && i == 0)
		{
			check = 1;
			do
			{
				printf("%c", string[i]);
				i++;
			} while (!ispunct(string[i]) && string[i] != ' ' && string[i] != '\n');
		}
		else if (string[i] == letter && (ispunct(string[i - 1]) || string[i - 1] == ' '))
		{
			do
			{
				printf("%c", string[i]);
				i++;
			} while (!ispunct(string[i]) && string[i] != ' ' && string[i] != '\n');
		}
	}

	if (check == 1)
	{
		printf("There is no words with such first letters.");
	}

	return 0;
}