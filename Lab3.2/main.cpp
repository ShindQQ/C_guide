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
	Swap places
	the maximum element among
	all negative elements
	matrix of real numbers on
	the minimum element among
	all positive. Dimensionality
	matrix of real numbers no
	more than 20x20. Current
	size and elements of the matrix
	enter from the keyboard
*/

int main()
{
	int array[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
	int array_size1;
	int array_size2;
	int max_num_negative = INT_MIN;
	int min_num_positive = INT_MAX;
	int coord1_i, coord1_j;
	int coord2_i, coord2_j;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter size of array (from 0 to 20) * (from 0 to 20): ");
	if (scanf("%d", &array_size1))
	{
		if (scanf("%d", &array_size2))
		{
			if (array_size1 > 0 && array_size1 < 20 && array_size2 > 0 && array_size2 < 20)
			{
				printf("Fill your array:\n");

				for (int i = 0; i < array_size1; i++)
				{
					for (int j = 0; j < array_size2; j++)
					{
						printf("[%d][%d] : ", i, j);
						if (!scanf("%d", &array[i][j]))
						{
							printf("Enter mistake");
							return 0;
						}
					}
					puts("");
				}

				printf("\nReceived array:\n");

				for (int i = 0; i < array_size1; i++)
				{
					for (int j = 0; j < array_size2; j++)
					{
						printf("[%d][%d] : %d\n", i, j, array[i][j]);
					}
					puts("");
				}

				for (int i = 0; i < array_size1; i++)
				{
					for (int j = 0; j < array_size2; j++)
					{
						if (max_num_negative < array[i][j])
						{
							max_num_negative = array[i][j];
							coord1_i = i;
							coord1_j = j;
						}
						else if (min_num_positive > array[i][j])
						{
							min_num_positive = array[i][j];
							coord2_i = i;
							coord2_j = j;
						}
					}
				}

				array[coord2_i][coord2_j] = max_num_negative;
				array[coord1_i][coord1_j] = min_num_positive;

				printf("\nReceived array:\n");

				for (int i = 0; i < array_size1; i++)
				{
					for (int j = 0; j < array_size2; j++)
					{
						printf("[%d][%d] : %d\n", i, j, array[i][j]);
					}
					puts("");
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
	}
	else
	{
		printf("Enter mistake");
	}

	return 0;
}