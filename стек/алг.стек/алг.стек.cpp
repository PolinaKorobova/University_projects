#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "stack.h"


int prior(char ch) {
	if (ch == '(') return 0;
	if (ch == ')') return 1;
	if (ch == '+' || ch == '-') return 2;
	if (ch == '*' || ch == '/') return 3;
	if (ch >= '0' && ch <= '9') return 10;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	stack* st;
	st = (stack*)malloc(sizeof(stack));
	st->top = -1;
	char str[256];
	printf("Введите строку: ");
	gets_s(str);

	int i = 0;
	while (str[i] != '\0') {


		if (str[i] == '(') {
			if (is_full(st)) {
				printf("Стек полный");
				exit(0);
			}
			else {
				push(st, '(');
			}
		}
		if (str[i] == ')') {
			if (is_empty(st)) {
				printf("Вырежение некорректно.");
				exit(0);
			}
			else {
				pop(st);
			}
		}
		i++;
	}
	if (is_empty(st)) {
		printf("Выражение корректно.\n");
	}
	else {
		printf("Вырежение некорректно.\n");
		exit(0);
	}

	



	i = 0;
	char rez[256] = "\0";
	int j = 0;
	stack* stc;
	stc = (stack*)malloc(sizeof(stack));
	stc->top = -1;
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			rez[j] = str[i];
			 j++;
			 rez[j] = ' ';
			 j++;
		}
		if (str[i] == '(') {
			push(stc, '(');
		}
		if (str[i] == ')') {
			while (peek(stc) != '(') {
				rez[j] = peek(stc);
				j++;
				rez[j] = ' ';
				j++;
				pop(stc);
			}
				if (peek(stc) == '(') {
					pop(stc);
				}
			
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			
			if (is_empty(stc)) {
				push(stc, str[i]);
			}
			else {
				if (prior(str[i]) > prior(peek(stc))) {
					push(stc, str[i]);
				
			}

				else {
					while (prior(str[i]) <= prior(peek(stc))) {
						rez[j] = peek(stc);
						j++;
						rez[j] = ' ';
						j++;
						pop(stc);
					}
					
					push(stc, str[i]);
				}
			}
		}
		i++;
	}
	while (!is_empty(stc)) {
		rez[j] = peek(stc);
		j++;
		rez[j] = ' ';
		j++;
		pop(stc);
	}
	printf("Польская запись:  %s\n", rez);



	
	stack* s;
	s = (stack*)malloc(sizeof(stack));
	s->top = -1;
	j=0;
	while (rez[j] != '\0') {
		if (rez[j] >= '0' && rez[j] <= '9') {
			push(s, rez[j]);
	}
		if (rez[j] == '+' || rez[j] == '-' || rez[j] == '*' || rez[j] == '/') {
			int num1 = peek(s) - '0';
			pop(s);
			int num2 = peek(s) - '0';
			pop(s);
			if (rez[j] == '+') {
				push(s, (char)(num1 + num2 + '0'));
			}
			if (rez[j] == '-') {
				push(s, (char)(num2 - num1 + '0'));
			}
			if (rez[j] == '*') {
				push(s, (char)(num1 * num2 + '0'));
			}
			if (rez[j] == '/') {
				push(s, (char)(num2 / num1 + '0'));
			}
			
		}
		j++;
	}
	printf("Результат вычисления выражения в постфиксной нотации: %c\n", peek(s));
}