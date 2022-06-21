struct Spisok
{
	int inf;
	Spisok* next;
};
Spisok* New();
int Size(Spisok* list);
void print(Spisok* list);
Spisok* addfirst(Spisok* list, int inf);
Spisok* addlast(Spisok* list, int inf);
Spisok* addhalf(Spisok* list,  int inf);
Spisok* Delete(Spisok* list, int inf);
