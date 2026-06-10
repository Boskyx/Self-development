#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
/*Insert has to return a pointer, otherwise is only the creation of a pointer locally but not visible for the main.
 * In this way the root is an updated pointer to the root structure, with inside the pointer to the other leafs of the three*/
struct node *insert(struct node *node, int number)
{
	if (node==NULL){return newNode(number);}
	if (node->data>=number){node->left=newNode(number);}
	else {node->right=newNode(number);}
	return node;

}
/*IT DOESN PRINT CORRECTLY*/
void print_tree(struct node *node)
{
	printf("Below the three\n");
	while(node)
	{
		printf("%d\n", node->data);
		printf("%d %d\n", node->left->data, node->right->data);
		node=node->left;
		if (node->left==NULL && node->right==NULL){return;}

	}

}
int main(void){
	struct node *root=NULL;
	root=insert(root, 20);
	root=insert(root, 10);
	root=insert(root, 30);
	print_tree(root);
	return 0;
}
