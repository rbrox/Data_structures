#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int arr[MAX];

// Base condition, empty queue
int front = -1;
int rear = -1;

void enqueue(int x)
{
    // Queue Overflow
    if (rear == MAX - 1 )
    {
        return;
    }
    else
    {
        // Enqueue x 
        arr[++ rear] = x;

    // Activate dormant queue
    if (front == -1)
    {
        ++ front;
    }
    }
    

}

void dequeue()
{
    // TO - DO

    // If no elements in the queue
    if(rear == -1)
    {
        // TO - DO
        printf("\nno elements in the queue\n");
        return;
    }
    // If elements are there in the queue
    else
    {
        // To - do
        ++ front;
    }
}

void display ()
{
    printf("\nList is:\n------------------------------\n");
    for (int i = front; i <= rear; ++i )
    {
        printf("%d\t", arr[i]);
    }
    printf("\n------------------------------\n");
}

void main()
{
    while(1)
    {
        int x;
        printf("\n1.enqueue\t2.Dequeue\t3.Displ\n\n");
        scanf("%d", &x);

        switch(x)
        {
            case 1: 
            printf("\nenter ele:\t");
            scanf("%d", &x);
            enqueue(x);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;
        }

    }
    


}