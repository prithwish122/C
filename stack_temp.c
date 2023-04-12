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
    init(&s1, 5);
    push(&s1, 10);
    if (push(&s1, 10))
        ;
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
    }
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