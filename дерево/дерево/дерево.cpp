#include <iostream>
#include "дерево.h"

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


 node*New( int inf) {////////
	node* d;
	d = (node*)malloc(sizeof node);
	d->info = inf;
	d->left = d->right = NULL;
	return d;
};
 node* Add(node* d, int inf) {
	 if (d == NULL)
		 return New(inf);
	 if (inf > d->info) d->right = Add(d->right, inf);
	 else d->left = Add(d->left, inf);
	 return d;
 };
 void Print(node* d) {
	 int level = 0;
	 if (d == NULL) return; 
	 level++;
	 Print(d->right);
	 printf("(Level %d) %d, ", level, d->info);
	 Print(d->left);
	 level--;
 };
 int Number_sheets(node* d) {
	 int count = 0;
	 if (d == NULL) return 0;
	 if (d->left = d->right = NULL) count++;
	 Number_sheets(d->left);
	 Number_sheets(d->right);
	 return count;
 };
 int Hight(node* d) {
	 int h = 0;
	 int max = 0;
	 if (d == NULL) return;
	 h++;
	 if (h > max) max = h;
	 Print(d->right);
	 Print(d->left);
	 h--;
	 return max - 1;
 };
 void Pre_order(node* d) {
	 if (d == NULL) return;
	 printf("%d, ", d->info); 
	 Pre_order(d->left); 
	 Pre_order(d->right);
 };
 void In_order(node* d) {
	 if (d == NULL) return;
	 In_order(d->left);
	 printf("%d, ", d->info);
	 In_order(d->right);
 };
 void Post_order(node* d) {
	 if (d == NULL) return;
	 Post_order(d->left);
	 Post_order(d->right);
	 printf("%d, ", d->info);
 };
