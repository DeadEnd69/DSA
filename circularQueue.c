#include <stdio.h>
#include <stdlib.h>

#define max 100

struct queueTemp
{
    int front, rear, arr[max];
};

typedef struct queueTemp queue;

void makeEmpty(queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isEmpty(queue *q)
{
    if (q->front > q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(queue *q)
{
    if (q->rear == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *q, int val)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    if (isFull(q) && q->front != 0)
    {
        q->rear = 0;
    }
    else if (isFull(q) && q->front == 0)
    {

        {
            printf("The queue is empty");
            exit(1);
        }
    }
    {
        q->arr[q->rear] = val;
    }
}

int dequeue(queue *q)
{

    if (isEmpty(q))
    {
        printf("The queue is empty.");
        exit(1);
    }
    else
    {

        int val = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            if (q->front == max - 1)
            {
                q->front = 0;
            }
            else
            {
                q->front++;
            }
        }
        return val;
    }
}

void traverse(queue q)
{
    if (isEmpty(&q))
    {
        printf("The queue is empty.");
    }
    else
    {
        for (int i = 0; i < max; i++)
        {
            printf("%d\t", q.arr[i]);
        }
    }
}

int main()
{
    queue q;
    makeEmpty(&q);
    for (int i = 0; i < 5; i++)
    {
        enqueue(&q, i);
    }
    traverse(q);
    return 0;
}