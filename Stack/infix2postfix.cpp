// Infix to Postfix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

typedef struct Stack {
    int top;
    int capacity;
    char *array;
} Stack;

int is_empty(Stack *S) {
    return (S->top == -1);
}

char peek(Stack *S) {
    return S->array[S->top];
}

char pop(Stack *S) {
    if (!is_empty(S)) {
        return S->array[S->top--];
    }
    return '$';
}

void push(Stack *S, char op) {
    S->array[++S->top] = op;
}

int priority(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

char *infix_to_postfix(char *infix) {
    int i, j;
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->top = -1;
    S->capacity = MAX_EXPR_SIZE;
    S->array = (char *)malloc(S->capacity * sizeof(char));

    char *postfix = (char *)malloc((MAX_EXPR_SIZE + 1) * sizeof(char));

    for (i = 0, j = 0; infix[i]; ++i) {
        if (isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(S, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(S) && peek(S) != '(') {
                postfix[j++] = pop(S);
            }
            if (!is_empty(S) && peek(S) != '(') {
                return NULL;
            } else {
                pop(S);
            }
        } else {
            while (!is_empty(S) && priority(infix[i]) <= priority(peek(S))) {
                postfix[j++] = pop(S);
            }
            push(S, infix[i]);
        }
    }

    while (!is_empty(S)) {
        postfix[j++] = pop(S);
    }
    postfix[j] = '\0';

    return postfix;
}

int main() {
    char infix[] = "a+(b*c)-d/f";
    char *postfix = infix_to_postfix(infix);
    if (postfix) {
        printf("Infix: %s\n", infix);
        printf("Postfix: %s\n", postfix);
    } else {
        printf("Invalid Expression\n");
    }
    return 0;
}
