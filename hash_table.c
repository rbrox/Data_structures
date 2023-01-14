/*Code written by Rishav Bhagat

An implementattion of a simplistic hash table which tries to minimise the searching time of a particular key

search O(n)
Insert O(1)

*/

// Linkers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structs & global var

typedef struct node
{
    char name[26];
    struct node *next; 
}node;

node table[26];

// Prototypes


// Main Function

void main()
{
    
}

int name_hasher(char *name)
{
    int ch = name[0];
return ch - 65;
}

void name_prompt()
{
    char name[25];
    printf("Enter name\n");
    scanf("%s", &name);
    int key = name_hasher(name);

    if(table[key].next == NULL)
    {
        table[key].name = name;
        return;
    }
    else
    {
        node *temp = table[key].next;
    }
    
}