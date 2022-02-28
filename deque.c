// array inplementation of dequeue

#include <stdio.h>
#include <stdlib.h>

typedef struct dequeArray
{
    int front, rear;
    int capacity;
    int *array;
} deque;

deque *new_deque(int size)
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

int isEmpty(deque *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(deque *q)
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
    int last = q->rear, first = q->front;
    do
    {
        printf("%d ", q->array[first]);
        first = (first + 1) % q->capacity;
    }while (first != last+1);
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
        q->rear = (q->rear + 1) % q->capacity;
        q->array[q->rear] = x;
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
    else if (q->front == -1)
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
        q->front = (q->front + q->capacity - 1) % q->capacity;
        q->array[q->front] = x;
    }
    return;
}

// void dequeue_front(deque *q)
// {
//     if (isEmpty(q))
//     {
//         printf("Deque is empty\n");
//     }
//     else if (q->front == q->rear)
//     {
//         q->front = q->rear = -1;
//     }
//     else
//     {
//         q->front = (q->front + 1) % q->capacity;
//     }
// }



int main()
{
    int size;
    scanf("%d", &size);
    deque *Q = new_deque(size);
    enqueue_rear(Q, 1);
    enqueue_rear(Q, 2);
    enqueue_rear(Q, 45);
    display_deque(Q);
    enqueue_front(Q, 12);
    enqueue_front(Q, 11);
    display_deque(Q);    
    return 0;
}
