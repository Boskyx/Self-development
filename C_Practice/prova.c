#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    struct node{
    int value;         //data stored in the node
    struct node *next; //pointer to a node struct
    };
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=10;
    printf("%d\n", *new_node); //prints the value 10
    printf("%d\n", &new_node->value); //prints the value of the memory
}