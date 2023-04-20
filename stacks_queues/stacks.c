#include <stdio.h>

// Maximum size of the stack
#define MAXSIZE 100

// The stack
int stack[MAXSIZE];
// Keep track of the top of the stack
int top = -1;

// Check if the stack is empty (Top = -1)
int isempty();
// Check if the stack is full (Top = MAXSIZE)
int isfull();
// Return the topmost element
int peek();
// Delete from the stack (LIFO)
int pop();
// Insert into the stack (LIFO)
int push(int data);

void main(){
   // Prefill stack with numbers from 0 to MAXSIZE/5
   for (int i = 0; i < (MAXSIZE/5); i++)
   {
      push(i);
   }
   printf("The maximum size of the stack is %d.\n", MAXSIZE);
   printf("The stack has been prefilled with values from 0 to %d.\n", MAXSIZE/5);
   printf("Element at top of the stack: %d.\n", peek());
   printf("Elements: \n");

   // Print stack data as along as the stack is not empty
   while(!isempty()) 
   {
      int data = pop();
      printf("%d\n",data);
   }
   printf("Stack full: %s\n" , isfull()?"True":"False");
   printf("Stack empty: %s\n" , isempty()?"True":"False");
}

// Check if the stack is empty (Top = -1)
int isempty(){
   if(top == -1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

// Check if the stack is full (Top = MAXSIZE)
int isfull(){
   if(top == MAXSIZE)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

// Return the topmost element
int peek(){
   return stack[top];
}

// Delete from the stack (LIFO)
int pop(){
   int data;
   // Ensure stack is not empty
   if(!isempty()) 
   {
      data = stack[top];
      top = top - 1;
      return data;
   } 
   else 
   {
      printf("Stack is empty. Could not retrieve data.\n");
   }
}

// Insert into the stack (LIFO)
int push(int data){
   // Ensure the stack is not full
   if(!isfull()) 
   {
      top = top + 1;
      stack[top] = data;
   } 
   else 
   {
      printf("Stack is full. Could not insert data.\n");
   }
}