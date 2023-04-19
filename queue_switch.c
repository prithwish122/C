//Queue Program using switch case --->>>

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
}Q;

void init(Q *q, int cap)
{
    q->front=q->rear=-1;
    q->capacity=cap;
    q->size=0;
    q->arr=(int*)malloc(cap*sizeof(int));
}

int isempty(Q *q)
{
    return( q->front==-1);
}

int isfull(Q *q)
{
    return(q->front==0 && q->rear==q->capacity-1 || q->rear==q->front-1);
}

void enqueue(Q *q, int item)
{
    if(!isfull(q))
    {
        //q->rear=q->rear+1;
        if(q->rear==q->capacity-1)
            q->rear=0;
       else if(q->rear==-1 && q->front==-1)
          {
            q->front=0;
            q->rear = 0;
          }
          else
          {
              q->rear=q->rear+1;
          }

           q->arr[q->rear]=item;
            q->size=q->size+1;
    }
    else
    {
        printf("Queue is full\n");
    }    
}

int dequeue(Q *q)
{
    int item;
    if(!isempty(q))
    {
        item=q->arr[q->front];
        q->size--;
        if(q->front==q->rear) //for last element
        {
            q->front=q->rear=-1;
        }
        else if(q->front==q->capacity-1) //for normal deletion
        {
                q->front=0;
        }
        else
          q->front++;
        return item;
    }  
    else
        return 404;
}

int main()
{
    Q q;
    int n,a ;
    init(&q,4);
    do
    {
        printf("\n1. Enqueue\t 2. Dequeue\t 3. Exit \nEnter your choice: ");;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter any number: ");
                scanf("%d",&a);
                enqueue(&q,a);
                printf("Items in Queue: %d\n",q.size);
                break;
            case 2:
                printf("Deq Operation: %d\n",dequeue(&q));
                printf("Items in Queue: %d\n",q.size);
                break;
            case 3:
                printf("::BYE::\n");
                break;
            default:
                printf("Sorry sir, please choose a correct option.\n");
                break;
        }
    }while(n!=3);
    
}