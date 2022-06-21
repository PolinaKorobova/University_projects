#include <iostream>
#include <locale.h>
#include "tree.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	node* d = NULL;
	char Str[8] = "9-2*3"; 
	d = MakeTree(0, 4, Str);
	printf("Выражение: %s", Str);
	printf("\nПрямой обход: ");
	Pre_order(d);
	printf("\nПоперечный обход: ");
	In_order(d);
	printf("\nОбратный обход: ");
	Post_order(d);
	printf("\nРезультат: %0.2f", CalcTree(d));
}

