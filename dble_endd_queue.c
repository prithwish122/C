//Double ended Queue Program using switch case --->>>

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

void rear_enqueue(Q *q, int item)
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

int front_dequeue(Q *q)
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
    {
        return 404;
    }
}

void front_enqueue(Q *q,int item)
{
    if(!isfull(q))
    {
        if(q->rear==-1 && q->front==-1)
        {
            q->rear=q->front=0;
        }
        else if(q->front==0)
        {
            q->front=q->capacity-1;
        }
        else
        {
            q->front=q->front-1;
        }
        q->arr[q->front]=item;
        q->size=q->size+1;
    }
    else
    {
        return;
    }
}

int rear_dequeue(Q *q)
{
    int item;
    if(!isempty(q))
    {
        item=q->arr[q->rear];
        q->size=q->size-1;
        if(q->front==q->rear)
        {
            q->rear=q->front=-1;
        }
        else if(q->rear==0)
        {
            q->rear=q->capacity-1;
        }
        else
        {
            q->rear=q->rear-1;
        }
        return item;
    }
    else
    {
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
    Q q;
    int n,a ;
    init(&q,6);
    do
    {
        printf("\n1. Front Enqueue\t 2. Front Dequeue\t 3. Rear Enqueue\t 4. Rear Dequeue\t 5. Show Front\t 6. Show Rear\t 7. Exit \nEnter your choice: ");;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter any number: ");
                scanf("%d",&a);
                front_enqueue(&q,a);
                printf("Items in Queue: %d\n",q.size);
                break;
            case 2:
                printf("Front Dequeue Operation: %d\n",front_dequeue(&q));
                printf("Items in Queue: %d\n",q.size);
                break;
            case 3:
                printf("Enter any number: ");
                scanf("%d",&a);
                rear_enqueue(&q,a);
                printf("Items in Queue: %d\n",q.size);
                break;
            case 4:
                printf("Rear Dequeue Operation: %d\n",rear_dequeue(&q));
                printf("Items in Queue: %d\n",q.size);
                break;
            case 5:
                printf("The first value is here: %d\n",Efront(&q));
                break;
            case 6:
                printf("The last value is here: %d\n",Erear(&q));
                break;
            case 7:
                printf("::BYE::\n");
                break;
            default:
                printf("Sorry sir, please choose a correct option.\n");
                break;
        }
    }while(n!=7);
    
}