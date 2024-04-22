#include <stdio.h>

#define MAX_SIZE 5

struct queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct queue qt;

int isEmpty(qt *q)
{
    if (q->rear < q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(qt *q)
{
    if (q->rear == MAX_SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(qt *q, int key)
{
    if (isFull(q))
    {
        printf("\nQueue overflow!\n");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = key;
    }
}

void dequeue(qt *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue unflow!\n");
    }
    else
    {
        int deleatedItem = q->items[q->front];
        q->front++;
    }
}

void traverse(qt *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d\n", q->items[i]);
        }
    }
}

int main()
{
    qt q;

    q.front = 0;
    q.rear = -1;

    int option;

    do
    {
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display all element\n");
        printf("Enter 4 to exit\nresponse: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int key;
            printf("\nEnter an item to enqueue: ");
            scanf("%d", &key);
            enqueue(&q, key);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            traverse(&q);
            break;
        }

    } while (option != 4);

    return 0;
}