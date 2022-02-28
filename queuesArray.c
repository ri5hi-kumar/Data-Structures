// An array implementation of queue

/*
    In this implementation we use a array which is circular. This array is not actually circular but we manipulate the indices
    of the array in such a way that it behaves as a circular array

    To reach the next index we use; index = (index + 1) % sizeof(arr)
    To reach the previous index we use; index = (index + sizeof(arr) - 1) % sizeof(arr)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arrayQueue
{
    int front, rear; // front is item enqueued first and rear is item enqueued last
    int capacity;
    int *array; // pointer to the array of integers
} queue;

queue *new_queue(int size) // reserves space in heap for queue
{
    if (size <= 0) // if input is not valid
    {
        return NULL;
    }

    queue *Q = (queue *)malloc(sizeof(queue));
    Q->front = Q->rear = -1;                             // in the start both rear and front are -1
    Q->capacity = size;                                  // size of the array which is used as queue
    Q->array = (int *)malloc(Q->capacity * sizeof(int)); // reserving space for array

    return Q; // returns the queue which have front and rear is -1 and array of size provided through function argument
}

int is_empty(queue *Q)
{
    if (Q->front == -1 && Q->rear == -1) // as given the values in the starting
    {
        return 1; // true if empty
    }
    return 0;
}

int is_full(queue *Q)
{
    if (is_empty(Q))
    {
        return 0;
    }
    if ((Q->rear + 1) % Q->capacity == Q->front) // if next index to rear is front then is full
    {
        return 1;
    }
    return 0;
}

void display_queue(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue --> ");
    int first = q->front, last = q->rear; // storing values in temporary variables so that we don't loose them
    while (last >= first)                 // till the rear becomes less than the front
    {
        printf("%d ", q->array[last]);
        last--;
    }

    printf("\n");
}

void enqueue(queue *q, int x)
{
    if (is_full(q))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->capacity; // incrementing rear to the next index
        q->array[q->rear] = x;                 // storing the item in the index
        if (q->front == -1)                    // check if the list was empty i.e if it is the first enqueue
        {
            q->front = q->rear; // both becomes 0
        }
        return;
    }
}

void dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    if (q->front == q->rear) // if only one item in the queue it becomes empty after dequeue
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->capacity; // else front is incremented and we don't worry about the element in the front
    }
}

// Driver code
int main()
{
    int size;
    scanf("%d", &size);
    queue *Q = new_queue(size);
    enqueue(Q, 1);
    enqueue(Q, 2);

    // display_queue(Q);
    // dequeue(Q);
    // dequeue(Q);
    display_queue(Q);
    dequeue(Q);
    dequeue(Q);
    // dequeue(Q);

    display_queue(Q);
    return 0;
}