#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include "Spisok.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	Spisok* list = NULL;
	FILE* file;
	char str[256];
	file = fopen("list.txt", "r");
	fscanf(file, "%[^\n]\n", str);
	fclose(file);
	int i = 0, j = 0;
	char number[16] = "\0";
	int a = 0;
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			number[j] = str[i];
			j++;
			number[j] = '\0';
		}
		else {
			if (a == 0) {
				list = addfirst(list,  atoi(number));
			}
			else {
				list = addlast(list, atoi(number));
			}
			j = 0;
			number[j] = '\0';
			a++;
		}
		i++;
	}
	list = addlast(list,  atoi(number));
	int choice = 0;
	int inf;
	while (choice != 7) {
		printf("--------------------\n");
		printf("Введите номер операции, которую хотите совершить:\n");
		printf("1. Добавить элемент в начало\n");
		printf("2. Добавить элемент в конец\n");
		printf("3. Добавить элемент в середину\n");
		printf("4. Удалить элемент\n");
		printf("5. Кол-во элементов в списке\n");
		printf("6. Вывести список\n");
		printf("7. Выход\n");
		printf("--------------------\n");
		printf("Операция номер: ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("Введите значение: ");
			scanf_s("%d", &inf);
			list = addfirst(list,  inf);
			break;
		case 2:
			printf("Введите значение: ");
			scanf_s("%d", &inf);
			list = addlast(list, inf);
			break;
		case 3:
			printf("Введите значение: ");
			scanf_s("%d", &inf);
			list = addhalf(list, inf);
			break;
		case 4:
			printf("Введите значение: ");
			scanf_s("%d", &inf);
			list = Delete(list, inf);
			break;
		case 5:
			printf("Кол-во элементов - %d\n", Size(list));
			break;
		case 6:
			printf("Список: ");
			print(list);
			break;
		default:
			break;
		}
	}
}
