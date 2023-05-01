#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef node * stack;


bool push(stack *myStack, int value);
int pop (stack *myStack);

int main()
{
    stack stack1 = NULL, stack2 = NULL;

    printf("Stack 1\n");
    int nodes_to_insert = 10;
    for (int i = 0; i <= nodes_to_insert; i++)
    {
        printf("\tIs %d added to the stack: %d\n", i, push(&stack1, i));
    }
    printf("\n");

    int t;
    while ((t = pop(&stack1)) != STACK_EMPTY)
    {
        printf("\t%d was removed from the stack \n", t);
    }

    printf("Stack 2\n");
    nodes_to_insert = 5;
    for (int i = 0; i <= nodes_to_insert; i++)
    {
        printf("\tIs %d added to the stack: %d\n", i, push(&stack2, i));
    }
    printf("\n");

    while ((t = pop(&stack2)) != STACK_EMPTY)
    {
        printf("\t%d was removed from the stack \n", t);
    }
}

bool push(stack *myStack, int value)
{
    node *new = malloc(sizeof(node));

    if (new == NULL) return false;

    new->value = value;
    new->next = (*myStack);
    
    (*myStack) = new;

    return true;
}

int pop (stack *myStack)
{
   // Assumption: Smallest Integer won't be pushed in the stack
   if ((*myStack) == NULL) return STACK_EMPTY;

   int value = (*myStack)->value;

   node *tmp = (*myStack);
   *myStack = (*myStack)->next;
   free(tmp);

   return value;
}