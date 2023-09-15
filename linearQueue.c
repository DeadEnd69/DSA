#include <stdio.h>
#include <conio.h>
#define max 100
struct queueTemp
{
    int arr[max];
    int front, rear;
};
typedef struct queueTemp queue;

void makeEmpty(queue *q)
{
    q->front = 0;
    q->rear = -1;
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

void enqueue(queue *q, int val)
{

    if (isFull(q))
    {
        printf("The queue is full.");
    }
    else
    {

        q->arr[++q->rear] = val;
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty.");
    }
    else
    {
        return q->arr[q->front++];
    }
}

void traverse(queue *q)
{
    if (isEmpty(q))
    {
        printf("No element to print.\n");
    }
    else
    {
        for (int i = 0; i <= q->rear; i++)
        {
            printf("%d\n", q->arr[i]);
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
    traverse(&q);
    return 0;
}