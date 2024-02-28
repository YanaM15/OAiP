// Разработать программу вывода фамилий и дат рождения студентов, не имеющих оценок 3. 
// Предусмотреть ввод исходной информации о четырех студентах : фамилия и инициалы, год рождения, год поступления в БГУИР, 
// оценки за первый семестр по предметам : физика, высшая математика, информатика.

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
		printf("1. Ввод данных.\n");
		printf("2. Сортировка.\n");
		printf("3. Добавление записи.\n");
		printf("4. Вывод на экран.\n");
		printf("5. Запись/Чтение данных.\n");
		printf("6. Завершение программы.\n");
		printf("Введите ваш выбор: ");
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
