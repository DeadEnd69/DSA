#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
struct stack
{
    int arr[MAX];
    int top;
};

typedef struct stack stack1;

void initializeStack(stack1 *s)
{
    s->top = -1;
}

int isFull(stack1 *s)
{
    if (s->top >= MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(stack1 *s)
{
    return (s->top == -1) ? 1 : 0;
}

void push(stack1 *s, int value)
{
    if (isFull(s))
    {

        exit(1);
    }
    else
    {
        s->arr[++s->top] = value;
    }
}

int pop(stack1 *s)
{
    if (isEmpty(s))
    {

        return 0;
    }
    else
    {
        return s->arr[s->top--];
    }
}

int peek(stack1 *s)
{
    if (isEmpty(s))
    {
        exit(1);
    }
    else
    {
        return s->arr[s->top];
    }
}
int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch)
{
    switch (ch)
    {
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

void convertInfixToPostfix(char *expression) // added output parameter
{
    int i, j;
    char output[strlen(expression)];
    stack1 st;
    initializeStack(&st);

    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (checkIfOperand(expression[i]))
            output[++j] = expression[i]; // changed here

        else if (expression[i] == '(')
            push(&st, expression[i]);

        else if (expression[i] == ')')
        {
            while (!isEmpty(&st) && peek(&st) != '(')
                output[++j] = pop(&st); // changed here
            if (!isEmpty(&st) && peek(&st) != '(')
                exit(1); // changed here
            else
                pop(&st);
        }
        else
        {
            while (!isEmpty(&st) && precedence(expression[i]) <= precedence(peek(&st)))
                output[++j] = pop(&st); // changed here
            push(&st, expression[i]);
        }
    }

    while (!isEmpty(&st))
        output[++j] = pop(&st); // changed here

    output[++j] = '\0'; // changed here

    printf("%s\t", output);
}

int main()
{
    char expression[] = "((a+(b*c))-d)";
    convertInfixToPostfix(expression);

    return 0;
}
