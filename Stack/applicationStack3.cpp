// To evaluate a postfix expression
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int evaluatePostfix(char *exp)
{
    stack<int> S;
    int length = strlen(exp);
    for (int i = 0; i < length; i++)
    {
        if (!isOperator(exp[i]))
        {
            int integer = (int)exp[i];
            S.push(exp[i]);
        }
        else if(isOperator(exp[i])){
            int op2 = S.pop();
            int op1 = S.pop();

        }
    }
    
}

int main()
{
}