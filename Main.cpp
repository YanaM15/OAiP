// ����������� ��������� ������ ������� � ��� �������� ���������, �� ������� ������ 3. 
// ������������� ���� �������� ���������� � ������� ��������� : ������� � ��������, ��� ��������, ��� ����������� � �����, 
// ������ �� ������ ������� �� ��������� : ������, ������ ����������, �����������.

#include <stdio.h>
#include <locale.h>
#include <windows.h>

#include "Function.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	do {
		printf("1. ���� ������.\n");
		printf("2. ����������.\n");
		printf("3. ���������� ������.\n");
		printf("4. ����� �� �����.\n");
		printf("5. ������/������ ������.\n");
		printf("6. ���������� ���������.\n");
		printf("������� ��� �����: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: enter();
			break;
		case 2: sort();
			break;
		case 3: enter_new();
			break;
		case 4: print();
			break;
		case 5: save();
			break;
		case 6: return 0;
		}
	} while (choice != 6);
	return 0;
}
