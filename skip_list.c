/*
Coded by Rishav Bhagat
An implementation of a skip list 
*/

// Linkers
#include<stdio.h>
#include<stdlib.h>

// Structs and Global var

typedef struct node
{
    struct node* top;
    struct node* next;
    struct node* under;
    int val;
}node;

int arr = {1,2,3,4,5,6,7,8,9,10};

// Protoypes
void node_parse(node* prev, int val);

// Main function

void main()
{

}


// Function declarations

void ground_create(int size, int arr[])
{
    node* temp = (node*) malloc(sizeof(node));

    node* head = temp;

    
   
}

void node_parse(node* prev, int val)
{
    node* temp = (node *)malloc(sizeof(node));
    prev -> next = temp;
    temp -> top = NULL;
    temp -> next = NULL;
    temp -> under = NULL;
    temp -> val = val;

    return temp;
}