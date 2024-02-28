
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>
#include <io.h>
#include "Function.h"

using namespace std;

 
 struct student
{
	char name[30];
    int birthyear;
	int entrance_year;
	int physics;
	int high_math;
	int comp_science;
};

static student students[30], temp[30];

int kol_student;

extern void enter()
{	
	register int i;
	printf("������� ���������� ���������, ��� ������� ������ ������� ����������.\n");
	scanf_s("%d", &kol_student);
	for (i = 0;i < kol_student;i++)
	{
		printf("\n");
		printf("������� ������� � �������� ��������:\n");
		getchar();
		gets_s(students[i].name, 30);	
		printf("������� ��� �������� ��������:\n");
		scanf_s("%d",&students[i].birthyear);
		printf("������� ��� ����������� ��������:\n");
		scanf_s("%d", &students[i].entrance_year);
		printf("������� ������ �������� �� ��������� ���������:\n");
		printf("������: ");
		scanf_s("%d",&students[i].physics);
		printf("����������: ");
		scanf_s("%d",&students[i].high_math);
		printf("�����������: ");
		scanf_s("%d",&students[i].comp_science);
	}
	printf("\n");
}

extern void enter_new()
{
	if (kol_student < 30)
	{
		printf("������� ������� � �������� ��������:\n");
		getchar();
		gets_s(students[kol_student].name, 30);
		printf("������� ��� �������� ��������:\n");
		scanf_s("%d", &students[kol_student].birthyear);
		printf("������� ��� ����������� ��������:\n");
		scanf_s("%d", &students[kol_student].entrance_year);
		printf("������� ������ �������� �� ��������� ���������:\n");
		printf("������: ");
		scanf_s("%d", &students[kol_student].physics);
		printf("����������: ");
		scanf_s("%d", &students[kol_student].high_math);
		printf("�����������: ");
		scanf_s("%d", &students[kol_student].comp_science);
		kol_student++;
	}
	else
		printf("������� ������������ ���������� ���������.\n");
}

extern int sort()
{
	int choice;
	do
	{
		printf("�������:\n");
		printf("1-���������� �� �������.\n");
		printf("2-���������� �� ���� ��������.\n");
		printf("3-���������� �� ���� �����������.\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: sort_name();
			break;
		case 2: sort_birthday();
			break;
		case 3: sort_entrence();
			break;
		}
	} while (choice > 4);
	printf("\n");
	return 0;
}
extern void sort_name()
{
	register int i, j;
	for (i = 1; i < kol_student; i++)
		for (j = kol_student - 1; j >= i; j--)
	{
		if (strcmp(students[j - 1].name, students[j].name) > 0)
		{
			temp[j] = students[j - 1];
			students[j - 1] = students[j];
			students[j] = temp[j];
		}
	}
}
extern void sort_entrence()
{
	register int i, j;
	for (i = 1; i < kol_student; i++)
		for (j = kol_student - 1; j >= i; j--)
	{
		if (students[j - 1].entrance_year > students[j].entrance_year)
		{
			temp[j] = students[j - 1];
			students[j - 1] = students[j];
			students[j] = temp[j];
		}
	}
}
extern void sort_birthday()
{
	register int i, j;
	for (i = 1; i < kol_student; i++) 
		for (j = kol_student - 1; j >= i; j--)
	    {
			if (students[j - 1].birthyear > students[j].birthyear)
			{
				temp[j] = students[j - 1];
				students[j - 1] = students[j];
				students[j] = temp[j];
			}
	    }
}

extern void print()
{
	register int i;

	printf("��������:\n");
	printf("1. ������� ������ � ���� ���������.\n");
	printf("2. �������  ������� � ���� �������� ���������, �� ������� ������ 3.\n");
	int choice;
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("���                ��� ����.     ��� ������.      ������         �����.       ������. \n");
		printf("--------------------------------------------------------------------------------------\n");
		for (i = 0;i < kol_student;i++)
		{
			printf("%s %12d %14d %13d %13d %13d\n", students[i].name, students[i].birthyear, students[i].entrance_year, students[i].physics, students[i].high_math, students[i].comp_science);
		}
		printf("\n");
	}
	if (choice == 2)
	{
	    printf("���                  ��� ����.  \n");
		printf("-------------------------------\n");
		for (i = 0;i < kol_student;i++)
		{
			if ((students[i].physics != 3) && (students[i].high_math != 3) && (students[i].comp_science != 3))
			printf("%s %12d \n", students[i].name, students[i].birthyear);
		}
		printf("\n");
	}
}
extern void save()
{
	int choice;
	printf("��������� ������/������ ������ �/�� ����� (1/2)\n");
	scanf_s("%d",&choice);
	if (choice == 1)
	{
		printf("������ ������ � ���� (students.dat).\n");
		FILE* f;
		if (fopen_s(&f, "students.dat", "w+b") != 0)
		{
			printf("������ �������� �����.\n");
			return;
		}
		for (int i = 0; i < kol_student; i++)
		{
			fwrite(&students[i], sizeof(student), 1, f);
		}
		fclose(f);
		printf("�������.\n");
	}
	if (choice == 2)
	{
		printf("������ ������ �� ����� (students.dat).\n");
		FILE* f;

		if (fopen_s(&f, "students.dat", "r") != 0)
		{
			printf("������ �������� �����.\n");
			return;
		}
		int num = 0;
		int s = sizeof(student);
		long l = _filelength(_fileno(f));
		if (l != 0)
		{
			num = l / s;
		}
		//printf("%d : %d\n", s, l);
		kol_student = num;
		for (int i = 0; i < num; i++)
		{
			fseek(f, i * s, SEEK_SET);
			fread(&students[i], sizeof(student), 1, f);
		}

		fclose(f);
		printf("�������.\n");

	}
}