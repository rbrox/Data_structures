/* 
Coded by Rishav Bhagat
An implementation to demostrate searching algorithms on a diverse set of elements
*/


// Linker section
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Global Declarations

#define RANGE 9999999
#define SIZE 1000
#define ELEMENT rand() % RANGE
#define FILL for ( i = 0; i < SIZE; i++) \
                arr[i] = ELEMENT
int arr[SIZE];


// Function Prototypes
void display();
int linear_search(int* arr, int x, int n);
int binary_search( int x, int fast, int slow);
void bubble_better(int n);


// Main function
void main()
{
    int i;
    printf("Constructed data set \n\n");
    srand(time(0));
    FILL;
    display();
    printf("\n\n After sorting\n\n");
    bubble_better(SIZE);
    display();

    
    //printf("%d\n", linear_search(arr, 8, 9));
    while (1)
    {
        printf("\n\nEnter element to be found:\t");
        scanf("%d", &i);
        if (binary_search(i, SIZE - 1, 0))
        {
            printf("\n\nFound");
        }
        else
            printf("\n\nNot Found");
    
    }
    
   
} 

int linear_search(int* arr, int x, int n)
{
    // Iterate through all the elements of the arry and then retrn 1 if the number target is found
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == x)
        {
            return 1;
        }     
    }
    return 0;
}


int binary_search( int x, int fast, int slow)
{
    int mid = (fast + slow) / 2;
    printf("%d\t", arr[mid]);
    if(arr[mid] == x)
        return 1;
    else if(slow >= fast)
        return 0;       
    else if(arr[mid] > x)
        return binary_search(x, mid - 1, slow);
    else if(arr[mid] < x)
        return binary_search(x, fast, mid + 1);        
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
        
    }
    
}

void bubble_better(int n)
{
  int flag = 10;

  while (flag != 0)
  {
    flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        ++flag;
      }
    }
  }
}  