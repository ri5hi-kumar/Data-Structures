// implementation of queue using Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{
	int data;
	struct queueNode *next;
}node;
node *head = NULL;
node *tail = NULL;

void displayQueue(){
	if(head == NULL && tail == NULL){
		printf("Queue is empty\n");
		return;
	}	
	node *temp = head;
	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node *getNewNode(){
	node *newNode = (node *)malloc(sizeof(node));
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}

void enqueue(){
	node *newNode = getNewNode();
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	tail->next = newNode;
	tail = newNode;
}

void dequeue(){
	if(head == NULL){
		printf("Queue is empty\n");
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	node *temp = head->next;
	free(head);
	head = temp;
}

int main(){
	enqueue();
	enqueue();
	enqueue();
	displayQueue();
	dequeue();
	displayQueue();
	return 0;
}