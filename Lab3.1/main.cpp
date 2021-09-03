#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define MAX_ARRAY_SIZE 20

/*
	In an array of integers
	replace with negative zeros
	items that stand right away
	after positive. Elements of
	array of not more than twenty.
	The dimension of the array and its
	elements enter with
	keyboard
*/

int main()
{
	int array[MAX_ARRAY_SIZE];
	int array_size;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter size of array (from 0 to 20): ");
	if (scanf("%d", &array_size))
	{
		if (array_size > 0 && array_size < 20)
		{
			printf("Fill your array:\n");

			for (int i = 0; i < array_size; i++)
			{
				printf("[%d] : ", i);
				if (!scanf("%d", &array[i]))
				{
					printf("Enter mistake");
					return 0;
				}
			}

			for (int i = 1; i < array_size; i++)
			{
				if (array[i - 1] > 0 && array[i] < 0)
				{
					array[i] = 0;
				}
			}

			printf("\nReceived array: ");

			for (int i = 0; i < array_size; i++)
			{
				printf("[%d] : %d\n", i, array[i]);
			}
		}
		else
		{
			printf("Size of array MUST be less than 20 and more than 0!");
		}
	}
	else
	{
		printf("Enter mistake");
	}

	return 0;
}