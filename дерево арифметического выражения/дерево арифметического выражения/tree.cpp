#include <iostream>
#include "tree.h"

node* New(int inf, char sign) {  //�������� ����� �������, ������ ���� � �����
	node* d;
	d = (node*)malloc(sizeof node);
	d->num = inf;
	d->sign = sign;
	d->left = d->right = NULL;
	return d;
}

int prior(char ch) {   //����������� ���������� ��������
	if (ch == '+' || ch == '-') return 2;
	if (ch == '*' || ch == '/') return 3;
	if (ch >= '0' && ch <= '9') return 10;
}

node* MakeTree(int first, int last, char* mass) //���������� ������ �� ������� ��� ������
{                                               //first, last ������ � ����� �������
	node* Tree = New(0, '0'); // ������� ����� �������
	int MinPrior = 10, i, k, prt;
	if (first == last) //����� ������� ����� ���� - �����
	{
		Tree->num = atoi (&mass[first]);  //������� �� ������ � �����
		Tree->left = NULL;
		Tree->right = NULL;
		return Tree; // �����
	}
	// ������� ��������� �������� � ���������� �����������
	for (i = first; i < last; i++)
	{
		prt = prior(mass[i]);
		if (prt <= MinPrior)
		{
			MinPrior = prt;
			k = i;
		}
	}
	Tree->sign = mass[k]; //�������� � ���������� �����������
	Tree->left = MakeTree(first, k - 1, mass); // ���������� ������ ����������
	Tree->right = MakeTree(k + 1, last, mass);
	return Tree;
}

void Pre_order(node* d) {  //������ �����
	if (d == NULL) return;
	if (d->num != 0) {     //������� �������� �����
		printf("%d ", d->num);  
	}
	if (d->sign != '0') {
		printf("%c ", d->sign);
	}
	Pre_order(d->left);  //�������� ����� ���������
	Pre_order(d->right);  //�������� ������ ���������
}
void In_order(node * d) {   //���������� �����
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
void Post_order(node * d) {   //�������� �����
	if (d == NULL) return;
	Post_order(d->left);  //�������� ����� ���������
	Post_order(d->right);  //������� ������ ���������
	if (d->num != 0) {   //������� �������� �����
		printf("%d ", d->num);
	}
	if (d->sign != '0') {
		printf("%c ", d->sign);
	}
}

float CalcTree(node* Tree)  //���������� �������� ���������
{
	float num1, num2;
	if (Tree->left == NULL) // ���� ��� ��������,
		return Tree->num; // ������� �����
	num1 = CalcTree(Tree->left); // ��������� ����������
	num2 = CalcTree(Tree->right);
	switch (Tree->sign) { // ��������� ��������
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}