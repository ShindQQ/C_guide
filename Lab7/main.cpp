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
	Write a Search Engine in
	student files that
	live in a hostel and
	output information about
	them in alphabetical order
	in ascending order
*/

struct Students
{
	char name[256];
	char surname[256];
	char patronymic[256];
	int lives;
};

int StrCount(FILE* fp);
void swap(char* arg1, char* arg2);
void swap(int& arg1, int& arg2);
Students* Sort(Students* arr, int size);
void print(Students* students, int count);

int main(int argc, char* argv[])
{
	FILE* fp = NULL;

	Students* students = NULL;

	const char filename_output[] = "out.txt";

	char filename_input[256];

	int count = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc < 2) {
		printf("Введіть назву файла: ");
		do {
			fgets(filename_input, 256, stdin);
			if (filename_input[0] == '\n')
			{
				printf("Текст не повинен бути пустим, спробуйте ще раз: ");
			}
		} while (filename_input[0] == '\n');
		filename_input[strlen(filename_input) - 1] = ' ';
	}
	else
	{
		strcpy(filename_input, argv[1]);
	}

	if ((fp = fopen(filename_input, "r")) == NULL)
	{
		printf("Помилка відкриття файлу %s!\n", filename_input);
		return 1;
	}

	count = StrCount(fp);

	students = (Students*)malloc(sizeof(Students) * count);

	for (int i = 0; i < count; i++)
	{
		if (fscanf(fp, "%s %s %s %d", students[i].surname, students[i].name, students[i].patronymic, &students[i].lives) != 4)
		{
			printf("Помилка зчитки з файлу %s!\n", filename_input);
			fclose(fp);
			return 1;
		}
	}

	fclose(fp);

	fp = fopen(filename_output, "w+");

	printf("Зчитанні дані з файлу:\n");
	print(students, count);

	students = Sort(students, count);

	printf("Відсортовані дані з файлу:\n");
	print(students, count);

	for (int i = 0; i < count; i++)
	{
		fprintf(fp, "%s %s %s %d\n", students[i].surname, students[i].name, students[i].patronymic, students[i].lives);
	}

	fclose(fp);

	return 0;
}

int StrCount(FILE* fp)
{
	int count = 0;

	while (!feof(fp))
	{
		fscanf(fp, "%*[^\n]\n");
		count++;
	}

	rewind(fp);

	return count;
}

void swap(char* arg1, char* arg2)
{
	char temp[256];

	strcpy(temp, arg1);
	strcpy(arg1, arg2);
	strcpy(arg2, temp);
}

void swap(int& arg1, int& arg2)
{
	int temp;

	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

Students* Sort(Students* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (strcmp(arr[i].surname, arr[j].surname) < 0)
			{
				swap(arr[i].surname, arr[j].surname);
				swap(arr[i].name, arr[j].name);
				swap(arr[i].patronymic, arr[j].patronymic);
				swap(arr[i].lives, arr[j].lives);
			}
		}
	}
	return arr;
}

void print(Students* students, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%s %s %s ", students[i].surname, students[i].name, students[i].patronymic);
		if (students[i].lives == 0)
		{
			printf("Не проживає\n");
		}
		else
		{
			printf("Проживає\n");
		}
	}
}