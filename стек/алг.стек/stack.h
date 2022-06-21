struct stack
{
	char mass[20];
	int top;
};

void push(stack* st, char ch);
void pop(stack* st);
char peek(stack* st);
bool is_empty(stack* st);
bool is_full(stack* st);
int size(stack* st); 
