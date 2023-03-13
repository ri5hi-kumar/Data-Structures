// array implementation of queue
#include<stdio.h>
#include<stdlib.h>
#define MAX_CAPACITY 10

struct queue{
	int n;
	int front;
	int rear;
	int array[MAX_CAPACITY];
};

void display(struct queue *q){
	if(q->front == -1){
		printf("Queue is empty\n");
		return;
	}
	for(int i = 0; i < q->n; i++){
		printf("%d\t", q->array[i]);
	}
	printf("\n");
}

void enqueue(struct queue *q, int x){
	if(q->n == MAX_CAPACITY){
		printf("Queue is full\n");
		return;
	}
	if(q->front == -1 && q->rear == -1){
		q->front = q->rear = 0;
		q->array[q->front] = x;
		q->n++;
		return;
	}
	q->array[++q->rear] = x;
	q->n++;
}

int dequeue(struct queue *q){
	if(q->front == -1){
		printf("Queue is empty\n");
		return -1;
	}
	int x = q->array[q->front];
	q->front++;
	q->n--;
	if(q->front > q->rear){
		q->front = q->rear = -1;
	}
	return x;
}

int main(){
	struct queue q;
	q.n = 0;
	q.front = -1;
	q.rear = -1;
	
	enqueue(&q, 1);
	enqueue(&q, 69);
	enqueue(&q, 2);
	
	display(&q);
}