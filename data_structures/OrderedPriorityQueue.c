#include <stdio.h>

#define MAX_SIZE 10

struct priorityQueue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct priorityQueue Q;

void createEmptyQueue(Q *PQ)
{
    PQ->front = 0;
    PQ->rear = -1;
}

int isEmpty(Q *PQ)
{
    if (PQ->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(Q *PQ)
{
    if (PQ->rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(Q *PQ, int newItem)
{
    // ordered priority queue
    if (isFull(PQ))
    {
        printf("\nQueue overflow\n");
    }
    else
    {
        int pos = 0;
        for (int i = 0; i <= PQ->rear; i++)
        {
            if (newItem < PQ->items[i])
                break;
            pos++;
        }
        for (int i = PQ->rear; i >= pos; i--)
        {
            PQ->items[i + 1] = PQ->items[i];
        }
        PQ->items[pos] = newItem;
        PQ->rear++;
    }
}

void dequeue(Q *PQ)
{
    if (isEmpty(PQ))
    {
        printf("\nQueue underflow\n");
    }
    else
    {
        int deletedItem = PQ->items[PQ->front];
        for (int i = 1; i <= PQ->rear; i++)
        {
            PQ->items[i - 1] = PQ->items[i];
        }
        PQ->rear--;
    }
}

void traverse(Q *PQ)
{
    if (isEmpty(PQ))
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        for (int i = 0; i <= PQ->rear; i++)
        {
            printf("%d\n", PQ->items[i]);
        }
    }
}

int main()
{
    Q PQ;

    createEmptyQueue(&PQ);

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
            enqueue(&PQ, key);
            break;

        case 2:
            dequeue(&PQ);
            break;

        case 3:
            traverse(&PQ);
            break;
        }

    } while (option != 4);

    return 0;
}