// implementation of stack using array
#include<stdio.h>
#include<stdlib.h>

int top = -1;

void displayStack(int *stack, int n){
	if(top == -1){
		printf("Stack is empty\n");
		return;
	}
	for(int i = 0; i <= top; i++){
		printf("%d\t", stack[i]);
	}
	printf("\n");
}

void push(int *stack, int n){
	if(top >= n - 1){
		printf("Stackoverflow\n");
		return;
	}
	top++;
	scanf("%d", &stack[top]);
}

int pop(int *stack){
	if(top == -1){
		printf("Stackunderflow\n");
		return -1;
	}
	top--;
	return stack[top + 1];
}

int peak(int *stack){
	return stack[top];
}

int main(){
	int n;
	printf("Enter the max size of the stack: ");
	scanf("%d", &n);
	
	int *stack = (int *)malloc(n);
	
	int temp = n;
	
	
	// operations
	while(temp--){
		push(stack, n);
	}
	displayStack(stack, n);
	
	printf("%d is popped\n", pop(stack));
	printf("%d is popped\n", pop(stack));
	displayStack(stack, n);
	
	return 0;
}