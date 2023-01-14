#include<stdio.h>
#include<stdlib.h>

// Declaration of the node
 struct node{
    int data;
    struct  node* next;
}node;

// Prototypes
struct node* push(struct node* ptr, int val);
struct node* intial(struct node* curr);
struct node* pop(struct node* curr);
void list_display(struct node* curr);
int list_search(struct node* curr, int target);
struct node* sort_list(struct node* curr);
struct node* skipper(struct node* head);
struct node* skip(struct node* head);

// Main Function 
void main()
{
    int swt, temp;
    struct node* curr;
    curr = intial(curr);

    while (1)
    {
        printf("Enter choice\n1.Push\t2.Display list\t3.Search\t4.Skipper\t5.Sort List\t6.Exit\n");
        scanf("%d", &swt);

        switch (swt)
        {
            case 1:
                
                printf("Enter val\n");
                scanf("%d", &temp);
                curr = push(curr, temp);
                break;

            case 2:
                list_display(curr);
                break;

            case 3:
                printf("\n\nEnter value to be found\n");
                scanf("%d", &temp);
                if(list_search(curr, temp) == 0)
                    printf("\nNot found\n");

                else
                    printf("\nFound\n");    
                break;

            case 4:
                curr = skipper(curr);
                break;
                    

            case 5:
                curr = sort_list(curr);
                break;

            default:
                exit(0);
        }
    }
    
    

    list_display(curr);

}

struct node* intial(struct node* curr)
{
    // Intital node
    curr = NULL;
    return curr;
}

struct node* push(struct node* ptr, int val)
{
    struct node* temp = (struct node*)malloc(sizeof(node));
    temp -> data = val;
    temp -> next = ptr;
    ptr = temp;
    return ptr;
}

void list_display(struct node* curr)
{
    
    for(struct node *temp = curr; temp != NULL; temp = temp -> next)
    {
         printf("%d", temp -> data);
    }
    

}

int list_search(struct node* curr, int target)
{
    for (;curr != NULL ;curr = curr -> next)
    {
        if (curr -> data == target)
            return 1;
    }
    return 0;
}

struct node* pop(struct node* curr)
{
    struct node* temp = curr;
    curr = curr -> next;
    free(temp);
    return curr;
}

struct node* sort_list(struct node* head){  
        //Node current will point to head  
        printf("Sorting......\n");
    
    struct node *NewHead, *run, *curr, *prev, *prev_cut; 
    int max;

        NewHead = intial(NewHead);
        for (int i = 0;head != NULL; ++i)
        {
            //list_display(head);
            max = head -> data;
            run = head;
            prev = run;
            for(int j = 0; run != NULL; run = run -> next)
            {
                if(max <= run -> data)
                {
                    // Snip points
                    max = run -> data;
                    curr = run;
                    prev_cut = prev; 
                }

                prev = run;
            }

            // Test
            printf("%d max = %d\n", i, max);
            NewHead = push(NewHead, max);

              if (prev_cut == curr)
            {
                head = prev_cut -> next;
            }
            else
                prev_cut -> next = curr -> next;
            
            // Snipping
        }

        list_display(NewHead);

        free(curr);
        return NewHead;
    }  


struct node* skipper(struct node* head){

    int swt = 0;
    struct node *slow = head, *fast; 
    for(fast = slow -> next;slow -> data == fast -> data && fast != NULL; fast = fast -> next, ++swt);
    slow -> next = fast;
    if(swt)
    {
        head = slow -> next;
        swt = 0;
    }
    return head;
}

struct node* skip(struct node* head){

    struct node *run = head;

    for(; run != NULL; run = run -> next)
    {
        run = skipper(run);
    }
    return head;
}