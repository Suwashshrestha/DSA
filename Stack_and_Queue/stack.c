#include <stdio.h>
#include<stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
    /* data */
};
struct SLL *top;
void push(int);
int pop();

int main()
{
    top = NULL;
    int choice, element;
    do
    {
        printf("1.push\n2.POP\n3.EXIT\n");
        printf("choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("element");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            printf("poped %d\n",pop());
            break;

        case 3:
            printf("bye\n");
            break;
        }
    } while (choice != 3);
    return 0;
}
void push(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode == NULL)
        printf("Memory allocation");
    else
    {
        NewNode->data = element;
        NewNode->next = NULL;
        if (top == NULL)
            top = NewNode;
        else
        {
            NewNode->next = top;
            top = NewNode;
        }
        printf("SUCCESS  %d is at top\n", top->data);
    }
}
int pop()
{
    struct SLL *temp;
    int element;
    if (top == NULL)
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        element = top->data;
        if (top->next == NULL)
        {
            temp = top;
            free(top);
            top = NULL;
        }

        else
        {
            temp = top;
            top = top->next;
            free(temp);
        }
        return element;
    }
}