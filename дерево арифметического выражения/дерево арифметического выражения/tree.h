struct node
{
	int num;
	char sign;
	node* left;
	node* right;
};
node* New(int num, char sign);
int prior(char ch);
node* MakeTree(int first, int last, char* mass);
void Pre_order(node* d);
void In_order(node* d);
void Post_order(node* d);
float CalcTree(node* Tree);
