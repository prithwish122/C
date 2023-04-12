/*Stack implementation in converting infix to postfix*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
} stack;

void init(stack *p, int size);
int isfull(stack *p);
void push(stack *p, int item);
int isempty(stack *p);
char pop(stack *p);
char peek(stack *p);
int isOperator(char ch);
int presedence(char ch);
char *infix_to_postfix(char *inf, stack *s);

int main()
{
    stack s1;
    init(&s1, 20);
    char infix[20] = "a+b+(c*d)+e/f";
    char *postfix = infix_to_postfix(infix, &s1);
    printf("%s\n", postfix);
    return 0;
}

void init(stack *p, int size)
{
    p->top = -1;
    p->size = size;
    p->arr = (char *)malloc(size * sizeof(char));
}

int isfull(stack *p)
{
    return (p->top == p->size - 1);
}

void push(stack *p, int item)
{
    if (isfull(p) != 1)
    {
        p->arr[++p->top] = item;
    }
}

int isempty(stack *p)
{
    return (p->top == -1);
}

char pop(stack *p)
{
    if (isempty(p))
    {
        return '$';
    }
    else
    {
        return p->arr[p->top--];
    }
}

char peek(stack *p)
{
    return (p->arr[p->top]);
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int presedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

char *infix_to_postfix(char *inf, stack *s)
{
    int i, j;
    int ilen = strlen(inf);
    char *pf = (char*)malloc(ilen*sizeof(char));
    for (i = 0, j = 0; i < ilen; i++)
    {
        if (inf[i] == ' ' || inf[i] == '\t') // error correction
        {
            continue;
        }
        else if (isalnum(inf[i])) // check for alpha-numeric number
        {
            pf[j++] = inf[i];
        }
        else if (inf[i] == '(') // check for first bracket
        {
            push(s, inf[i]);
        }
        else if (inf[i] == ')') // check for second bracket
        {
            while (peek(s) != '(' && s->top > -1)
            {
                pf[j++] = pop(s);
            }
            if (s->top == -1 && s->arr[s->top + 1] != '(')
            {
                return ("Invalid Expression\n");
            }
            else
            {
                s->top--;
            }
        }
        else if (isOperator(inf[i])) // check for operator
        {
            while (presedence(inf[i]) <= presedence(peek(s)) && s->top > -1)
            {
                pf[j++] = pop(s);
            }
            push(s, inf[i]);
        }
    } // end of for loop
    while (s->top > -1)
    {
        pf[j++] = pop(s);
    }
    pf[j] = '\0'; // append null to the character array
    return pf;
}