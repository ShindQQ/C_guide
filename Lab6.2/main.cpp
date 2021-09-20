#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>

/*
	Given a natural number n> 1.
	Write a recursive function that
	outputs all prime factors
	of this number in descending order
	taking into account the multiplicity.
*/

void quest(int number, int div = 2);
void print(int number);

int main()
{
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter n: ");
	if (!scanf("%d", &n))
	{
		printf("It`s not num");
		return 1;
	}

	printf("Result: ");

	quest(n);

	return 0;
}

void quest(int number, int div)
{
	if (number != 1)
	{
		while (number % div == 0)
		{
			print(div);
			number /= div;
		}
		quest(number, ++div);
	}
	else
	{
		print(1);
	}
}

void print(int number)
{
	if (number != 1)
	{
		printf("%d * ", number);
	}
	if (number == 1)
	{
		printf("1");
	}
}