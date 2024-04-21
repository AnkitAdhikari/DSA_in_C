#include <stdio.h>

#define SIZE 10

struct stack
{
    int items[SIZE];
    int tos;
};

typedef struct stack stack;

void createEmptyStack(stack *S)
{
    S->tos = -1;
}

int isFull(stack *S)
{
    if (S->tos == SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *S)
{
    if (S->tos == -1)
        return 1;
    else
        return 0;
}

void push(stack *S, int newitem)
{
    if (isFull(S))
    {
        printf("\nStack overflow\n");
    }
    else
    {
        S->tos = S->tos + 1;
        S->items[S->tos] = newitem;
    }
}

void pop(stack *S)
{
    if (isEmpty(S))
    {
        printf("\nStack underflow\n");
    }
    else
    {
        printf("\nDeleted item: %d\n", S->items[S->tos]);
        S->tos = S->tos - 1;
    }
}

void top(stack *S)
{
    if (isEmpty(S))
    {
        printf("\nEmpty Stack\n");
    }
    else
    {
        printf("\nTop item: %d\n", S->items[S->tos]);
    }
}

void traverse(stack *S)
{
    if (isEmpty(S))
    {
        printf("\nStack is empty\n");
    }
    else
    {
        for (int i = S->tos; i >= 0; i--)
        {
            printf("%d\n", S->items[i]);
        }
    }
}

int main()
{
    stack S;
    createEmptyStack(&S);
    int option;

    do
    {
        printf("Enter 1 to check is stack full\n");
        printf("Enter 2 to check is stack empty\n");
        printf("Enter 3 to push\n");
        printf("Enter 4 to pop\n");
        printf("Enter 5 to see top\n");
        printf("Enter 6 to display all element\n");
        printf("Enter 7 to exit\nresponse: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            if (isFull(&S))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;

        case 2:
            if (isEmpty(&S))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

        case 3:
            int key;
            printf("\nEnter an item to push: ");
            scanf("%d", &key);
            push(&S, key);
            break;

        case 4:
            pop(&S);
            break;

        case 5:
            top(&S);
            break;

        case 6:
            traverse(&S);
            break;
        }

    } while (option != 7);

    return 0;
}
