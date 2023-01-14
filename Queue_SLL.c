#include <stdio.h>
#include <stdlib.h>

// Struct declaratipn
typedef struct node{
    int data;
    struct node* next;
}node;

void enqueue ();
void display ();
void dequeue();

node * front = NULL, *rear = NULL, *curr = NULL;
// Main function
void main()
{
    int swt;
    while(1)
    {
        printf("\nEnter\n");
        printf("1.Enqueue\t2.Display\t3.Dequeue\n");
    scanf("%d", &swt);
     switch (swt)
        {
            case 1:
                enqueue();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Dequeing...\n\n");
                dequeue();
                break;

            case 4:
                
                break;
                    

            case 5:
                
                break;

            default:
                exit(0);
        }
    }
    
    }

void enqueue ()
{
    node* temp = (node*)malloc(sizeof(node));
    
    temp -> next = rear;
    rear = temp;
    printf("Enter value\n");
    scanf("%d", &temp -> data);

}

void display ()
{
    printf("\nCurrent Queue\n\n");
   for (node* temp = rear; temp != front; temp = temp -> next)
    printf("%d, ", temp -> data);
}

void dequeue()
{
    for(node* temp = rear; temp != NULL; temp = temp -> next)
    {
        if((temp -> next) -> next == NULL)
        {
            temp -> next = front;
            free(temp -> next);
            break;
        }
    }
    return;
}