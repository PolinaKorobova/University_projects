#include <iostream>
#include "spisok.h"

Spisok* New() {
	Spisok* list;
	list = (Spisok*)malloc(sizeof(Spisok));
	list->inf = 0;
	list->next = NULL;
	return list;
}

int Size(Spisok* list) {
	int count = 0;
	Spisok*temp = list;
	while (temp != 0) {
		temp = temp->next;
		count++;
	}
	return count;
}
void print(Spisok* list) {
	Spisok* temp = list;
	while (temp != 0) {
		printf("%d ", temp->inf);
		temp = temp->next;
	}
	printf("\n");
}

Spisok* Delete(Spisok* list, int inf) {
	int index = 0;
	Spisok* temp = list;
	while (temp != NULL && temp->inf != inf) {
		temp = temp->next;
		index++;
	}
	if (temp == NULL) {
		return list;
	}
	if (index == 0) {
		return list->next;
	}
	
	int count = 0;
	Spisok* temp2 = list;
	while (count != index - 1) {
		temp2 = temp2->next;
		count++;
	}
	temp2->next = temp2->next->next;
	return list;
}
Spisok* addfirst(Spisok* list, int inf) {
	 Spisok*el = New();
	el->inf = inf; 
	el->next = list;
	return el;
	}

Spisok* addlast(Spisok* list, int inf) {
	Spisok* el = New();
	Spisok* temp = list;
	while (temp->next != NULL) {
		temp = temp->next;
	}
		temp->next = el;
		el->inf = inf;
		el->next = NULL;
	
	return list;
}
Spisok* addhalf(Spisok* list, int inf) {
	Spisok*temp = list;
	int count = 0;

	while (count != Size(list)/2 - 1 && temp->next != NULL) {
		temp = temp->next;
		count++;
	}
	if (temp->next == NULL) {
		return list;
	}
	Spisok*el = New();
	el->inf = inf;
	el->next = temp->next; 
	temp->next = el; 
	return list;
}
