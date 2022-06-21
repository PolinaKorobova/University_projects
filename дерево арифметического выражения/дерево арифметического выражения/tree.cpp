#include <iostream>
#include "tree.h"

node* New(int inf, char sign) {  //создание новой вершины, вносим знак и число
	node* d;
	d = (node*)malloc(sizeof node);
	d->num = inf;
	d->sign = sign;
	d->left = d->right = NULL;
	return d;
}

int prior(char ch) {   //определение приоритета операции
	if (ch == '+' || ch == '-') return 2;
	if (ch == '*' || ch == '/') return 3;
	if (ch >= '0' && ch <= '9') return 10;
}

node* MakeTree(int first, int last, char* mass) //построение дерева по массиву без скобок
{                                               //first, last начало и конец отрезка
	node* Tree = New(0, '0'); // создать новую вершину
	int MinPrior = 10, i, k, prt;
	if (first == last) //длина отрезка равне нулю - число
	{
		Tree->num = atoi (&mass[first]);  //перевод из строки в число
		Tree->left = NULL;
		Tree->right = NULL;
		return Tree; // выход
	}
	// находим последнюю операцию с наименьшим приоритетом
	for (i = first; i < last; i++)
	{
		prt = prior(mass[i]);
		if (prt <= MinPrior)
		{
			MinPrior = prt;
			k = i;
		}
	}
	Tree->sign = mass[k]; //операция с наименьшим приоритетом
	Tree->left = MakeTree(first, k - 1, mass); // рекурсивно строим поддеревья
	Tree->right = MakeTree(k + 1, last, mass);
	return Tree;
}

void Pre_order(node* d) {  //прямой обход
	if (d == NULL) return;
	if (d->num != 0) {     //выводим значение корня
		printf("%d ", d->num);  
	}
	if (d->sign != '0') {
		printf("%c ", d->sign);
	}
	Pre_order(d->left);  //обоходим левое поддерево
	Pre_order(d->right);  //обоходим правое поддерево
}
void In_order(node * d) {   //поперечный обход
	if (d == NULL) return;
	In_order(d->left);
	if (d->num != 0) {
		printf("%d ", d->num);
	}
	if (d->sign != '0') {
		printf("%c ", d->sign);
	}
	In_order(d->right);
}
void Post_order(node * d) {   //обратный обход
	if (d == NULL) return;
	Post_order(d->left);  //обоходим левое поддерево
	Post_order(d->right);  //обходим правое поддерево
	if (d->num != 0) {   //выводим значение корня
		printf("%d ", d->num);
	}
	if (d->sign != '0') {
		printf("%c ", d->sign);
	}
}

float CalcTree(node* Tree)  //вычисление значения выражения
{
	float num1, num2;
	if (Tree->left == NULL) // если нет потомков,
		return Tree->num; // вернули число
	num1 = CalcTree(Tree->left); // вычисляем поддеревья
	num2 = CalcTree(Tree->right);
	switch (Tree->sign) { // выполняем операцию
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}