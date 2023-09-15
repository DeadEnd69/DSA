#include <stdio.h>
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
        printf("The stack is full. Unable to push the element.");
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
        printf("The stack is empty. Unable to pop the element.");
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
        printf("The stack is empty. Unable to peek the top of the stack.");
    }
    else
    {
        return s->arr[s->top];
    }
}

int main()
{
    stack1 s;
    initializeStack(&s);

    push(&s, 3);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", pop(&s));
    }

    return 0;
}