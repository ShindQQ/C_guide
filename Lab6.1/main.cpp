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
	Given a natural number n and
	sequence of natural
	numbers a1, a2, ... an. Show all
	sequence elements that are
	prime numbers. Write
	simple definition function
	numbers
*/

void quest(int* array, int size);
int is_prime(int number);
void print(int number);

int main()
{
	int* array;
	int size;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter size of sequence: ");
	if (!scanf("%d", &size))
	{
		printf("It`s not num");
		return 1;
	}

	array = (int*)malloc(sizeof(int) * size);
	if (!array)
	{
		printf("Bad memory allocation");
		return 1;
	}

	printf("Enter sequence: ");

	for (int i = 0; i < size; i++)
	{
		if(!scanf("%d", &array[i]))
		{
			printf("It`s not num");
			return 1;
		}
	}

	printf("\nEntered sequence: ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	
	printf("\nPrime numbers: ");

	quest(array, size);

	return 0;
}

void quest(int* array, int size)
{
	int check = 0;

	for (int i = 0; i < size; i++)
	{
		if (is_prime(array[i]))
		{
			print(array[i]);
		}
	}
}

int is_prime(int number)
{
	if (number == 1)
	{
		return 0;
	}

	for (int i = 2; i < number; i++)
	{
		if (!(number % i))
		{
			return 0;
		}
	}

	return 1;
}

void print(int number)
{
	printf("%d ", number);
}