//Basic template of Queue(Enqueue and Dequeue)
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int cap;
    int size;
    int *arr;
}Q;

void init(Q *q, int cap)
{
    q->cap=cap;
    q->size=0;
    q->front=q->rear=-1;
    q->arr=(int*)malloc(cap*sizeof(int));
}

int isFull(Q *q)
{
    return (q->rear+1==q->front || q->front==0 && q->rear==q->cap-1);
}

int isEmpty(Q *q)
{
    return(q->front==-1);
}

void enqueue(Q *q, int item)
{
    if(!isFull(q))
    {
        if(q->front==-1 && q->rear==-1)
        {
            q->front=0;
        }
        if(q->rear==q->cap-1)
        {
            q->rear=-1;
        }
        q->rear=q->rear+1;
        q->arr[q->rear]=item;
        q->size=q->size+1;
    }//End of parent if-condition.
    else
    {
        printf("Queue excided the limit...\n");
    }
}

int dequeue(Q *q)
{
    int item;
    if(!isEmpty(q))
    {
        if (q->rear!=q->front)//If rear is not equal to front
        {
            item=q->arr[q->front];
            q->front=q->front+1;
            if(q->front==q->cap)//If front is equal to capacity
            {
                q->front=0;
            }
        }
        else//If rear is equal to front
        {
            item=q->arr[q->front];
            q->front=q->rear=-1;
        }
        q->size=q->size-1;
        return item;
    }
    else
    {
        printf("Condition underflow, Item not found... ");
        return 404;
    }
}

int Efront(Q *q)
{
    return (q->arr[q->front]);
}

int Erear(Q *q)
{
    return (q->arr[q->rear]);
}

int main()
{
    Q q1;
    int capacity;
    printf("Enter the capacity of the Queue: ");
    scanf("%d",&capacity);
    init(&q1,capacity);
    enqueue(&q1,30);
    enqueue(&q1,10);
    enqueue(&q1,50);
    enqueue(&q1,52);
    enqueue(&q1,47);
    enqueue(&q1,78);
    printf("The value is here: %d\n",dequeue(&q1));
    enqueue(&q1,1);
    enqueue(&q1,48);
    enqueue(&q1,22);
    printf("The value is here: %d\n",dequeue(&q1));
    enqueue(&q1,8);
    enqueue(&q1,49);
    printf("The first value is here: %d\n",Efront(&q1));
    printf("The last value is here: %d\n",Erear(&q1));

}