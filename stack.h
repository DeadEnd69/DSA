#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int top;
    unsigned capacity;
    int *array;
} stack1;

int isFull(stack1 *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(stack1 *stack)
{
    return stack->top == -1;
}

void push(stack1 *stack, int item)
{
    if (isFull(stack))
    {

        return;
    }
    stack->array[++stack->top] = item;
}

int pop(stack1 *stack)
{
    if (isEmpty(stack))
    {

        return -1;
    }
    return stack->array[stack->top--];
}

int peek(stack1 *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top];
}

void initializeStack(stack1 *stack, unsigned capacity)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
}
