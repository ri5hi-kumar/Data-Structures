// implementation of stack using Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode{
	int data;
	struct stackNode *next;
}node;

node *top = NULL;

void displayStack(){
	if(top == NULL){
		printf("Stack is empty\n");
		return;
	}
	node *temp = top;
	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void pushNode(){
	node *newNode = (node *)malloc(sizeof(node));
	scanf("%d", &newNode->data);
	newNode->next = top;
	top = newNode;
}

void popNode(){
	if(top == NULL){
		printf("Stack is empty\n");
		return;
	}
	node *temp = top;
	top = top->next;
	free(temp);
}

int topStack(){
	if(top == NULL){
		printf("Stack is empty\n");
		return -1 ;
	}
	return top->data;
}

int main(){
	popNode();
	pushNode();
	pushNode();
	pushNode();
	pushNode();
	pushNode();
	displayStack();
	popNode();
	displayStack();
	popNode();
	popNode();
	popNode();
	popNode();
	displayStack();
	return 0;
}