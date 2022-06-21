struct node
{
	int info;
	node* left;
	node* right;
};
node* New(node* d, int inf);
node* Add(node* d, int inf);
void Print(node* d);
int Number_sheets(node* d);
int Hight(node* d);
void Pre_order(node* d);
void In_order(node* d);
void Post_order(node* d);

