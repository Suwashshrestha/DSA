#include <stdio.h>
void heap_sort(int num[], int n);
void max_heap(int num[],int n);
void max_heapify(int num[],int i, int n);
void swap(int a, int b);
void enqueue(int num[]);
void dequeue(int num[]);
void display(int num[]);
int i=0;
int main()
{
    int n=1, Num[5];
    char choice;
    while(n != 4)
    {
        printf("choise number for following:\n");
        printf("1.Enqeue\n");
        printf("2.Deqeue\n");
        printf("3.Dispaly\n");
        printf("4.EXIT\n");
        printf("choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Insertion number\n");
            enqueue(Num);
            break;

        case 2:
            printf("deletion number\n");
            dequeue(Num);
           
            break;
        case 3:
            printf("Display\n");
            display(Num);
        
            break;
        case 4:
            printf("exit\n");
            break;
        default:
            printf("INVALID INPUT\n");
            break;
        }    
    }
}
void enqueue(int num[])
{

    printf("enter the number");
    scanf("%d",&num[i]);
    i=i+1;
    heap_sort(num, i);

}
void dequeue(int num[])
{
    if(i==0)
        printf("queue is empty");
    else
    {
        num[0] = num[i-1];
        i = i-1;
        heap_sort(num,i);
    }

}
void display(int num[])
{
    if(i==0)
        printf("queue is empty\n");
    else
    {
        printf("queue is:");
        for(int j=0; j<i;j++)
        {
            printf("%d ",num[j]);
            
        }
    }
}
void max_heapify(int num[],int i, int n)
{
    int largest =i;
    int l = 2*i;
    int r = 2*i + 1;
    if(l<=n&&num[l]>num[largest])
        largest=l;
    if (r<=n && num[r]>num[largest])
        largest=r;
    if (largest!=i)
    {
        swap(num[i],num[largest]);
        max_heapify(num,largest,n);
    }
}
void heap_sort(int num[], int n)
{
    max_heap(num,n);
    for (int i = n; i >= 2; i--)
    {
        swap(num[1],num[n]);
        n=n-1;
        max_heapify(num,1,n);
    }
}
void max_heap(int num[],int n)
{
    for (int i = n/2; i >= 1; i--)
    {
        max_heapify(num , i ,n);
    }
}
void swap(int a, int b)
{
     int temp = a;
    a = b;
    b = temp;

}
