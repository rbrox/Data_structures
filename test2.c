
// Linkers
#include <stdio.h>
#include <stdlib.h>



// Global variables

typedef struct nodes{
    struct nodes *parent; 
    struct nodes *left_child;
    struct nodes *right_child;
    int val;     
}node;

node* root = NULL;

// Prototypes
node* prep_node(int x);
void node_insert(int x, node* curr_node);
void postorder(node* curr_node);
int tree_height(node* curr_node);
void balance_node(node* passed_node);

// Main functions

void main()
{
    int x, y;
    do
    {
        
        printf("\n1.Insert, 2.Postorder\n");
        scanf("%d", &x);

        switch (x)
        {
            case 1:
                printf("Insert val:\t");
                scanf("%d", &y);
                node_insert(y, root);
                break;
    
            case 2:
                printf("\nList\n");
                postorder(root);
                break;

            case 3: 
                printf("\nHeight\n");
                printf("%d\n", tree_height(root)); 
                break;
        }
    }while(x != 0);
    
    

}

// Function declarations

node* prep_node(int x)
{
    node* temp = malloc(sizeof(node));          
    temp -> parent = NULL;
    temp -> left_child = NULL;              
    temp -> right_child = NULL;
    temp -> val = x;
    return temp;
}



void node_insert(int x, node* curr_node)
{
    
    // No elemnts in the Binary tree
    if( ! root )// Alter is root == NULL
    {
        root = prep_node(x);
    }
    // Binary tree has a root element
    else
    {
        // x sent to left, less than curr_node val
        if(curr_node -> val > x)
        {
            if( ! curr_node -> left_child ) // curr_node -> left_child == NULL
            {
                curr_node -> left_child = prep_node(x);
                return;
            }
            else
            {
                node_insert(x, curr_node -> left_child);
            }
        }
        else
        {
            if( ! curr_node -> right_child ) // curr_node -> left_child == NULL
            {
                curr_node -> right_child = prep_node(x);
                return;
            }
            else
            {
                node_insert(x, curr_node -> right_child);
            }
        }
    }   
}


void postorder(node* curr_node)
{
    if(curr_node -> left_child)
    {
        postorder(curr_node -> left_child);
    }
    
    if(curr_node -> left_child)
    {
        postorder(curr_node -> right_child);
    }

    printf("%d,\t", curr_node -> val);
}

// A function to compute the height of tree
int tree_height(node* curr_node)
{
    if(curr_node == NULL)
    {
        return 0;
    }
    else if (curr_node -> left_child == NULL && curr_node -> right_child == NULL)
    {
        return 1;
    }
    else if(curr_node -> left_child == NULL)
    {
        return 1 + tree_height(curr_node -> right_child);
    }
    else if(curr_node -> right_child == NULL)
    {
        return 1 + tree_height(curr_node -> left_child);
    }
    else 
    {
        int left_h = tree_height(curr_node -> left_child);
        int right_h = tree_height(curr_node -> right_child);

        if (left_h < right_h)
        {
            return right_h + 1;
        }
        else
        {
            return left_h + 1;
        }
    }
}


// A funtion to calculate the balancing factor of each node

void balance_node(node* passed_node)
{
    // The balancing factor is calculated by taking the
    // height of each sub tree and subtract the left from the right

    int left_height;
    int right_height;

    if(passed_node -> left_child != NULL)
    {
        left_height = tree_height(passed_node -> left_child);
    }
    else
    {
        left_height = 0;
    }
    
    if(passed_node -> right_child != NULL)
    {
        right_height = tree_height(passed_node -> right_child);
    }
    else
    {
        right_height = 0;
    }

    // The balancing factor is the measure used for judging whether 
    // the subtrees on either side of the node in discussion,
    int balance_factor = right_height - left_height;
    return balance_factor;

}