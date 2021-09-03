#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

/*
	Given a natural number N.
	a) Rearrange the first and
	the last digit of the number N.
	b) Assign a unit of c
	the beginning and end of the recording
	numbers N
*/

int main()
{
	int N;
	int temp_N;
	int count = 0;
	int first_number;
	int last_number;
	int power;
	int ressult;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("Enter N: ");

	if (scanf("%d", &N))
	{
		temp_N = N;

		while (temp_N > 0)
		{
			count++;
			temp_N /= 10;
		}
		printf("count = %d\n", count);

		power = pow(10, count - 1);

		first_number = N / int(power);

		last_number = N % 10;

		N /= 10;

		N = N * 10 + first_number;

		N %= int(power);

		N += last_number * int(power);

		printf("Reaaranged number: %d\n", N);
		
		if(count >= 9)
		{
			printf("Too much numbers to print int");
		}
		else
		{
			ressult = N * 10 + 1 + 1 * pow(10, count + 1);

			printf("Adding 1: %d", ressult);
		}
	}
	else
	{
		printf("Enter mistake");
	}

	return 0;
}