#include <stdio.h>

// Maximum size of the queue
#define MAXSIZE 6

// The queue
int queue[MAXSIZE];
// The start of the queue
int front = 0;
// The end of the queue
int rear = -1;
// Items in the queue
int itemCount = 0;

// Return the first item in the queue (FIFO)
int peek();
// Check if the queue is empty (When itemCount is 0)
int isEmpty();
// Check if the queue is empty (When itemCount is MAXSIZE)
int isFull();
// The size of the queue
int size();
// Insert into the queue as the last item
void insert(int data);
// Remove data from the queue as the first item
int removeData();

void main() {
    printf("Maximum size of the queue is %d\n", MAXSIZE);
    printf("The queue is prefilled from 0 to %d\n", MAXSIZE-1);
    //  Prefill with values from 0 to MAXSIZE - 1
    for (int i = 0; i < (MAXSIZE-1); i++)
    {
        insert(i);
    }
    
    // Show if the queue is full
    if(isFull()) 
    {
        printf("Queue is full!\n");   
    }
    else
    {
        printf("Queue is not yet full!\n");
    }

    // remove one item 
    int num = removeData();
	
    printf("Element removed: %d\n",num);
    printf("Element at front: %d\n",peek());
    printf("Queue:  ");
	
    while(!isEmpty()) 
    {
        int n = removeData();           
        printf("%d ",n);
    }   
}

// Return the first item in the queue (FIFO)
int peek() {
   return queue[front];
}

// Check if the queue is empty (When itemCount is 0)
int isEmpty() {
    if (itemCount == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check if the queue is empty (When itemCount is MAXSIZE)
int isFull() {
    if (itemCount == MAXSIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// The size of the queue
int size() {
   return itemCount;
} 

// Insert into the queue as the last item
void insert(int data) {
    // Check if the queue is full
    if(!isFull()) 
    {
        // Correct the rear position
        if(rear == MAXSIZE-1) 
        {
            rear = -1;            
        }
        queue[++rear] = data;
        itemCount++;
    }
}

// Remove data from the queue as the first item
int removeData() {
    int data = queue[front++];
    // Correct the front position when queue is full
    if(front == MAXSIZE) 
    {
        front = 0;
    }
    itemCount--;
    return data;  
}