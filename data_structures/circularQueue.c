#include <stdio.h>

#define MAX_SIZE 10

struct cqueue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct cqueue q;

void createEmptyQueue(q *CQ)
{
    CQ->front = CQ->rear = MAX_SIZE - 1;
}

int isEmpty(q *CQ)
{
    if (CQ->front == CQ->rear)
        return 1;
    else
        return 0;
}

int isFull(q *CQ)
{
    if ((CQ->rear + 1) % MAX_SIZE == CQ->rear)
        return 1;
    else
        return 0;
}

void enqueue(q *CQ, int newItem)
{
    if (isFull(CQ))
    {
        printf("\nQueue overflow!\n");
    }
    else
    {
        CQ->rear = (CQ->rear + 1) % MAX_SIZE;
        CQ->items[CQ->rear] = newItem;
    }
}

void dequeue(q *CQ)
{
    if (isEmpty(CQ))
    {
        printf("\nQueue underflow!\n");
    }
    else
    {
        CQ->front = (CQ->front + 1) % MAX_SIZE;
        int deleted_item = CQ->items[CQ->front];
    }
}

void traverse(q *CQ)
{
    if (isEmpty(CQ))
    {
        printf("\nQueue Empty\n");
    }
    else
    {
        int i = CQ->front;
        do
        {
            i = (i + 1) % MAX_SIZE;
            printf("%d\n", CQ->items[i]);
        } while (i != CQ->rear);
    }
}

int main()
{
    q CQ;

    createEmptyQueue(&CQ);

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
            enqueue(&CQ, key);
            break;

        case 2:
            dequeue(&CQ);
            break;

        case 3:
            traverse(&CQ);
            break;
        }

    } while (option != 4);

    return 0;
}