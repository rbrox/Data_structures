#include<stdio.h>
#include<stdlib.h>

// Structure node declaration, Global declaration
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node *head = NULL;

// Prototypes

node * get_node(int x);
void insert_head(int x);
void insert_tail(int x);
void delete_node(int x);
void print_forward();
void print_backward();


// Main function
void main()
{
    while(1)
    {
        int flag, x;
        printf("\n\n1.Insert at head\n2.Insert at tail\n3.Print head first\n4.Print tail first\n5.Delete Node\n\n");
        printf("\nEnter command:\t");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter desired input:\t");
            scanf("%d", &x);
            insert_head(x);
            break;
        
        case 2:
            printf("\nEnter desired input:\t");
            scanf("%d", &x);
            insert_tail(x);
            break;

        case 3:
            print_forward();
            break;

        case 4: 
            print_backward();
            break;

        case 5: 
            printf("\nEnter desired input:\t");
            scanf("%d", &x);
            delete_node(x);
            break;

        default:
            break;
        }
    }
    
}


// Function to malloc a node and pass its address
node * get_node(int x)
{
    node* temp = (node *)malloc(sizeof(node));
    temp -> data = x;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

// Function to create node at head
void insert_head(int x)
{
    node* temp = get_node(x);

    if(head)
    {
        head -> prev = temp;
    }
    temp -> next = head;
    head = temp;
    return;
}

// Function to delete particular node
void delete_node(int x)
{
    node* temp = head;

    while(temp)
    {
        if(temp -> data == x)
        {
            // Head is the previous element
            if(temp -> prev == head)
            {
                head = temp -> next;
                temp -> next -> prev = head;
            }

            // The last element is the one to be deleted hence next ele is NULL 
            else if( ! temp -> next)
            {
                temp -> prev -> next = NULL;
            }

            // Genral case
            else
            {
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
            }

            // Clearing data of temp

            printf("Deleted value %d at location %u", temp -> data, temp);

            temp -> next = NULL;
            temp -> prev = NULL;
            free(temp);
            return;
        }

        temp = temp -> next;
    }

    printf("The element is not present in the list\n");

    return;
}

// Function to create node at tail
void insert_tail(int x)
{
    node *temp = get_node(x);
    node * tail = head;

    while(tail -> next)
    {
        tail = tail -> next;
    }

    if(head)
    {
        tail -> next = temp;
    }
    else
    {
        head = temp;
    }
    temp -> prev = tail; 
}

// Function to print elements from head first
void print_forward()
{
    // List is empty condition
    if(! head)
    {
        printf("\nEmpty list\n");
        return;
    }

    node *temp = head;
    printf("\nThe list head first\n");
    while(temp)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    } 
}


// Function to print elements from tail first
void print_backward()
{
    // List is empty condition
    if(! head)
    {
        printf("\nEmpty list\n");
        return;
    }
    node* tail = head;

    while(tail -> next)
    {
        tail = tail -> next;
    }
    printf("\nThe list tail first\n");
    while(tail)
    {
        printf("%d\t", tail -> data);
        tail = tail -> prev;
    }
}
/*
FUNCTIONAL & IMPLEMENTATION DETAILS

The objective of this peice of code is to implement a Doubly Linked List.

*/