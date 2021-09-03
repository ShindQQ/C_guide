#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

/*
	According to the entered quantity
	received points for the subject
	student for the semester
	determine its score in
	kind of: excellent, very good,
	good, satisfactory,
	enough, unsatisfactory
*/

int main()
{
	int grade;
	short flag = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter grade: ");

	if (scanf("%d", &grade))
	{
		if (grade <= 100 && grade >= 95)
		{
			flag = 1;
		}
		else if (grade < 95 && grade >= 85)
		{
			flag = 2;
		}
		else if (grade < 85 && grade >= 75)
		{
			flag = 3;
		}
		else if (grade < 74 && grade >= 65)
		{
			flag = 4;
		}
		else if (grade < 65 && grade >= 60)
		{
			flag = 5;
		}
		else if (grade < 60 && grade >= 0)
		{
			flag = 6;
		}

		switch (flag)
		{
			case 1:
			{
				printf("Excellent");
				break;
			}
			case 2:
			{
				printf("Very good");
				break;
			}
			case 3:
			{
				printf("Good");
				break;
			}
			case 4:
			{
				printf("Satisfactory");
				break;
			}
			case 5: 
			{
				printf("Enough");
				break;
			}
			case 6:
			{
				printf("Unsatisfactory");
				break;
			}
			default:
			{
				printf("Unreal grade");
				break;
			}

		}
	}
	else
	{
		printf("Enter mistake");
	}

	return 0;
}