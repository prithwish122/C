//Basic template of Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void append(Node **phead,int data)
{
    Node *new_node;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=NULL;
    if(*phead==NULL)
    {
        *phead=new_node;
    }
    else
    {
        Node *ptr;
        ptr=*phead;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;

    }
    
}

void display(Node **phead)
{
    Node *ptr=*phead;
    while(ptr!=NULL)
    {
        printf("%d,",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    Node *head;
    int data;
    head=NULL;
    printf("Enter the Element:");
    scanf("%d",&data);
    append(&head,data);
    printf("Enter the Element:");
    scanf("%d",&data);
    append(&head,data);
    printf("Enter the Element:");
    scanf("%d",&data);
    append(&head,data);
    printf("Enter the Element:");
    scanf("%d",&data);
    append(&head,data);
    printf("Enter the Element:");
    scanf("%d",&data);
    append(&head,data);
    display(&head);
    return 0;   
}