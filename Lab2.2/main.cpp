#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<windows.h>

/*
	Given real numbers x, e.
	Calculate with accuracy e
	infinite amount and specify
	the number of considered terms
*/

int main()
{
	double x;
	double e;
	double result = 0;
	double temp_result;
	double temp_value = 0;
	int iteration = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("Enter x: ");

	if (scanf("%lf", &x))
	{
		printf("Enter e: ");
		if (scanf("%lf", &e))
		{
			if (e > 0 && e < 1)
			{
				do
				{
					temp_result = result;
					temp_value = iteration;

					if (iteration < 2)
					{
						result = 1;
					}
					else
					{
						for (int i = iteration; i > 1; i--)
						{
							temp_value *= (i - 1);
						}
					}
					
					result += pow(x, 2 * iteration) / (pow(2, iteration) * temp_value);
					iteration++;
					printf("[%d], result: %lf\n", iteration, result);
					
				} while (fabs(result - temp_result) > e);

				printf("Iterations: %d\n", iteration);
				printf("Result: %lf", result);
			}
			else
			{
				printf("e must be from 0 to 1");
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