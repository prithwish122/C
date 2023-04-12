/*Stack implementation in evaluating a postfix equation*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
} stack;

void init(stack *s, int size)
{
    s->top = -1;
    s->size = size;
    s->arr = (char *)malloc(size * sizeof(char));
}

void push(stack *s, char pos);
void postfix_evl(stack *s, char *pos);
int isfull(stack *s);
int isempty(stack *s);
char pop(stack *s);
int isoperator(char ch);
char peek(stack *s);

int main()
{
    stack s1;
    init(&s1, 100);
    char postfix[100];
    printf("Enter the Postfix Expression: ");
    scanf("%s",&postfix);
    postfix_evl(&s1, postfix);
    printf("The evaluated value of the equation is %c", peek(&s1));
    return 0;
}

int isfull(stack *s)
{
    return (s->top == s->size - 1);
}

void push(stack *s, char pos)
{
    int full = isfull(s);
    if (full == 0)
    {
        s->arr[++s->top] = pos;
    }
}

int isempty(stack *s)
{
    return (s->top == -1);
}

char pop(stack *s)
{
    int empty = isempty(s);
    if (empty == 0)
    {
        return (s->arr[s->top--]);
    }
}

int isoperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^');
}

char peek(stack *s)
{
    return (s->arr[s->top]);
}

void postfix_evl(stack *s, char *pos)
{
    int ilen = strlen(pos);
    for (int i = 0, j = 0; i < ilen; i++)
    {
        if (pos[i] == ' ' || pos[i] == '\t')
        {
            continue;
        }
        else if (isdigit(pos[i]))
        {
            push(s, pos[i]);
        }
        else if (isoperator(pos[i]))
        {
            if (pos[i] == '+')
            {
                int a = pop(s);
                int b = pop(s);
                a = a - 48;
                b = b - 48;
                int c = b + a;
                push(s, c + 48);
            }
            else if (pos[i] == '-')
            {
                int a = pop(s);
                int b = pop(s);
                a = a - 48;
                b = b - 48;
                int c = b - a;

                push(s, c + 48);
            }
            else if (pos[i] == '*')
            {
                int a = pop(s);
                int b = pop(s);
                a = a - 48;
                b = b - 48;
                int c = b * a;
                push(s, c + 48);
            }
            else if (pos[i] == '/')
            {
                int a = pop(s);
                int b = pop(s);
                a = a - 48;
                b = b - 48;
                int c = b / a;
                push(s, c + 48);
            }
            else if (pos[i] == '^')
            {
                int a = pop(s);
                int b = pop(s);
                a = a - 48;
                b = b - 48;
                int c = a + b;
                push(s, c + 48);
            }
        }
    }
}