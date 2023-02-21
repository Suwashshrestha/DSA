#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
    /* data */
};
struct SLL *front, *rear;
void enqueue(int);
int dequeue();
int main()
{
    rear = NULL;
    front = NULL;
    int choice, element;
    do
    {
        printf("1.enqueue\n2.deqeue\n3.EXIT\n");
        printf("choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("element");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:
            printf("dequeue %d\n",dequeue());
            break;

        case 3:
            printf("bye\n");
            break;
        }
    } while (choice != 3);
    return 0;
}
void enqueue(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        printf("Memory allocation");
    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        if (rear == NULL)
        {
            front= rear = NewNode;
        }
        else
        {
            NewNode->next = rear;
            rear = NewNode;
        }
        printf("SUCCESS  %d is at enqueue\n", rear->data);
    }
}
int dequeue()
{
    struct SLL *temp;
    int element;
    if (front == NULL)
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        element = front->data;
        if (front->next == NULL)
        {
            temp = front;
            free(front);
            front = NULL;
        }

        else
        {
            temp = front;
            front = front->next;
            free(temp);
        }
        return element;
    }
}