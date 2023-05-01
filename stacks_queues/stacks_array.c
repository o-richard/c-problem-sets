#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct stack
{
    int values[STACK_LENGTH];
    int top;
} stack;

bool push(stack *myStack, int value);
int pop(stack *myStack);

int main()
{
   // Initialize two stacks
   stack stack1 = {.top = EMPTY}, stack2 = {.top = EMPTY};

   printf("Stack 1\n");
   for (int i = 0; i <= STACK_LENGTH; i++)
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
   for (int i = 0; i <= (STACK_LENGTH/2); i++)
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
   if ((myStack->top) >= STACK_LENGTH - 1) return false;

   (myStack->top)++;
   myStack->values[(myStack->top)] = value;
   return true;
}

int pop (stack *myStack)
{
   // Assumption: Smallest Integer won't be pushed in the stack
   if ((myStack->top) == EMPTY) return STACK_EMPTY;

   int value = myStack->values[(myStack->top)];
   (myStack->top)--;
   return value;
}