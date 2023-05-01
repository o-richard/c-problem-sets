#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct queue
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *myQueue);
bool enqueue(queue *myQueue, int value);
int dequeue(queue *myQueue);

int main()
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
    myQueue->head = NULL;
    myQueue->tail = NULL;
}

bool enqueue(queue *myQueue, int value)
{
    node *new = malloc(sizeof(node));

    if (new == NULL) return false;

    new->value = value;
    new->next = NULL;

    // Update the tail
    if (myQueue->tail != NULL)
    {
        myQueue->tail->next = new;
    }
    myQueue->tail = new;

    // Ensure the head is okay (When NULL)
    if (myQueue->head == NULL)
    {
        myQueue->head = new;
    }
    return true;
}

int dequeue(queue *myQueue)
{
    // Ensure Queue is not empty
    if (myQueue->head == NULL) return QUEUE_EMPTY;

    // Save the state of the head
    node *tmp = myQueue->head;

    int value = tmp->value;

    // Remove node from queue
    myQueue->head = myQueue->head->next;
    if ((myQueue->head) == NULL)
    {
        myQueue->tail = NULL;
    }

    free(tmp);

    return value;
}