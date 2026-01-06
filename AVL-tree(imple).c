//AVL tree implementation
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node *left,*right;
	int height;
};
int max(int a,int b){
	return (a>b)?a:b;
}
int height(struct Node *n) {
	return (n==NULL)?0:n->height;
}
struct Node* newNode(int key)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->key=key;
	node->left=node->right=NULL;
    node->height=1;
    return node;
}
struct Node* minValueNode(struct Node* node)
{
	struct Node* current=node;
	while(current->left!=NULL)
	{
		current = current->left;
		return current;
	}
}
//right rotation
struct Node* rightRotation(struct Node* y)
{
	struct Node* x = y->left;
	struct Node* T2 = x->right;
	x->right =y;
	y->left =T2;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}
int main()
{
	
}
