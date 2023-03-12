// array inplementation of dequeue

/* In this implementation when we enqueue in front, if there is no space in the front, i.e the front = 0 is already filled,
the operation will add element in the back but will make that index front, and display_deque() will always start from 
the front and goes till rear. */

#include <stdio.h>
#include <stdlib.h>

typedef struct dequeArray
{
    int front, rear;
    int capacity;
    int *array;
} deque;

deque *new_deque(int size)      // same as in queue
{
    if (size <= 0)
    {
        return NULL;
    }

    deque *Q = (deque *)malloc(sizeof(deque));
    Q->front = -1;
    Q->rear = -1;
    Q->capacity = size;
    Q->array = (int *)malloc(Q->capacity * sizeof(int));
    return Q;
}

int isEmpty(deque *q)       // is empty if front and rear have same value as given will making a new deque
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(deque *q)        // is full when the next index to the rear is front
{
    if ((q->rear + 1) % q->capacity == q->front)
    {
        return 1;
    }
    return 0;
}

void display_deque(deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque is empty\n");
        return;
    }
    int last = q->rear, first = q->front;       // storing front and rear in temporary variables so that we don't loose refrence
    do              // do-while coz when deque is full, last+1 is equal to front already
    {
        printf("%d ", q->array[first]);
        first = (first + 1) % q->capacity;      // taking circular step through each iteration 
    } while (first != last + 1);        // last+1 coz we start from front and will have to go to rear
    printf("\n");
}

void enqueue_rear(deque *q, int x)
{
    if (isFull(q))
    {
        printf("Deque is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->capacity;      // going to next index
        q->array[q->rear] = x;      // putting item in it
        if (q->front == -1)
        {
            q->front = q->rear;
        }
    }
    return;
}

void enqueue_front(deque *q, int x)
{
    if (isFull(q))
    {
        printf("Deque is full\n");
    }
    else if (q->front == -1)        // takes care of the case when list is empty i.e a enqueue_rear operation is not performed yet
    {
        q->front = (q->front + 1) % q->capacity;
        q->array[q->front] = x;
        if (q->rear == -1)
        {
            q->rear = q->front;
        }
    }
    else
    {
        q->front = (q->front + q->capacity - 1) % q->capacity;  // goes one index back in a circular array and taken care when front = 0
        q->array[q->front] = x;
    }
    return;
}

void dequeue_front(deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque is empty\n");
    }
    else if (q->front == q->rear)       // only one element is present
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->capacity;        // moves one index forward
    }
    return;
}

void dequeue_rear(deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque is empty\n");
    }
    else if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->rear = (q->rear + q->capacity - 1) % q->capacity;        // moves one index back
    }
    return;
}



// test it out through the follwing code
int main()
{
    int size;
    scanf("%d", &size);
    deque *Q = new_deque(size);

    // testing enqueue operations
    enqueue_rear(Q, 1);
    enqueue_rear(Q, 2);
    enqueue_rear(Q, 45);
    display_deque(Q);
    enqueue_front(Q, 12);
    enqueue_front(Q, 11);
    display_deque(Q);

    // testing dequeue operations
    dequeue_front(Q);
    dequeue_rear(Q);
    display_deque(Q);
    return 0;
}
