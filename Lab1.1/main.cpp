#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<windows.h>

/*
	Enter from the keyboard
	current time and determine the time
	days (am - from 0 to 12, pm - from
	12 to 24)
*/

int main()
{
	int time;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Enter time: ");

	if (scanf("%d", &time))
	{
		if (time >= 0 && time < 12)
		{
			printf("%d is am", time);
		}
		else if (time > 12 && time <= 24)
		{
			printf("%d is pm", time);
		}
		else if (time == 12)
		{
			printf("It`s noon");
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