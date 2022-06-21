#include "stack.h"

void push(stack* st, char ch) {
	st->top++;
	st->mass[st->top] = ch;

}
void pop(stack* st) {
	st->top--;

}
char peek(stack* st) {
	return st->mass[st->top];
}
bool is_empty(stack* st) {
	if (st->top < 0) {
		return true;
	}
	else {
		return false;
	}
}
bool is_full(stack* st) {
	if (st->top >= 20) {
		return true;
	}
	else {
		return false;
	}
}
int size(stack* st) {
	return st->top++;
}
