#include<stdio.h>
#include<stdlib.h>

// Declaration of the node
struct node{
    int data;
    struct  node* next;
}*head = NULL;


void push()
{
    // Mallocing the node
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    // list is empty
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        head -> next = temp;
        head = temp;
    }
}

void pop()
{
    // Stack underflow
    if(head == NULL)
    {
        return;
    }
    else
    {
        head = head -> next;
    }
    return;
}