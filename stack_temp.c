/*Using stack for the first time*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
} stack;

void init(stack *p, int size);
int push(stack *p, int item);
int isfull(stack *p);
int pop(stack *p);
int isempty(stack *p);

int main()
{
    stack s1;
    int n,x,i;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);//n=20
    init(&s1, n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value you want to push: ");
        scanf("%d",x);
        if(x==0)
        {
            break;
        }
        else
        {
        if (push(&s1, x))
        {
        printf("Overflow\n");
        }
        }
    }
    //printf("%d popped from the stack\n",pop(&s1));
    for(i=0;i<n;i++)
    {
        if (pop(&s1))
        {
        printf("Underflow\n");
        }
        else
        {
            printf("%d is popped\n", pop(&s1));
        }
    }
   /* push(&s1, 10);
    push(&s1, 10);
    push(&s1, 10);
    printf("Popped value %d\n",pop(&s1));
    printf("Popped value %d\n",pop(&s1));
    printf("Popped value %d\n",pop(&s1));
    printf("Popped value %d\n",pop(&s1));

    if (push(&s1, 10))
    {
        printf("Overflow\n");
    }
    if (pop(&s1))
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d is popped\n", pop(&s1));
    }*/
    return 0;
}

void init(stack *p, int size)
{
    p->top = -1;
    p->size = size;
    p->arr = (int *)malloc(size * sizeof(int));
}

int push(stack *p, int item)
{
    if (isfull(p))
    {
        return 1;
    }
    else
    {
        p->arr[++p->top] = item;
        printf("%d is pushed to stack\n",item);
        return 0;
    }
}

int isfull(stack *p)
{
    return (p->top == p->size - 1);
}

int pop(stack *p)
{
    if (isempty(p))
    {
        return 1;
    }
    else
    {
        return p->arr[p->top--];
    }
}

int isempty(stack *p)
{
    return (p->top == -1);
}