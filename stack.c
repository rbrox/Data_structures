#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int arr[MAX];

// Base condition, empty stack
int top = -1;

void push(int x)
{
    // Stack overflow
    if( top == MAX - 1)
    {
        return;
    }
    else
    {
        arr[++ top] = x;
        return;
    }
}

void pop()
{
    // Stack Underflow
    if( top == -1)
    {
        return;
    }
    else
    {
        arr[-- top] = 0;
        return;
    }
}