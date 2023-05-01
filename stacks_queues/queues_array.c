#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_LENGTH 10
#define HEAD 0
#define TAIL (-1)
#define QUEUE_EMPTY INT_MIN

typedef struct queue
{
    int values[QUEUE_LENGTH];
    int head, tail, itemCount;
} queue;

void init_queue(queue *myQueue);
bool enqueue(queue *myQueue, int value);
int dequeue(queue *myQueue);

int main ()
{
    queue q1, q2;

    init_queue(&q1);
    init_queue(&q2);

    printf("Queue 1\n");
    int nodes_to_insert = 10;
    for (int i = 0; i <= nodes_to_insert; i++)
    {
        printf("\tIs %d added to the queue: %d\n", i, enqueue(&q1, i));
    }
    printf("\n");

    int t;
    while ((t = dequeue(&q1)) != QUEUE_EMPTY)
    {
        printf("\t%d was removed from the queue \n", t);
    }

    printf("Queue 2\n");
    nodes_to_insert = 5;
    for (int i = 0; i <= nodes_to_insert; i++)
    {
        printf("\tIs %d added to the queue: %d\n", i, enqueue(&q2, i));
    }
    printf("\n");

    while ((t = dequeue(&q2)) != QUEUE_EMPTY)
    {
        printf("\t%d was removed from the queue \n", t);
    }
}

void init_queue(queue *myQueue)
{
    myQueue->head = HEAD;
    myQueue->tail = TAIL;
    myQueue->itemCount = 0;
}

bool enqueue(queue *myQueue, int value)
{
    if (myQueue->itemCount == QUEUE_LENGTH) return false;
    
    myQueue->tail++;
    myQueue->values[(myQueue->tail)] = value;
    myQueue->itemCount++;

    if (myQueue->tail == (QUEUE_LENGTH - 1))
    {
        myQueue->tail = TAIL;
    }

    return true;
}

int dequeue(queue *myQueue)
{
    // Ensure Queue is not empty
    if (myQueue->itemCount == 0) return QUEUE_EMPTY;

    int value = myQueue->values[(myQueue->head)];
    myQueue->head++;
    myQueue->itemCount--;

    if (myQueue->head == QUEUE_LENGTH)
    {
        myQueue->head = HEAD;
    }

    return value;
}