// Basic template of Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void append(Node **phead, int data)
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*phead == NULL)
    {
        *phead = new_node;
    }
    else
    {
        Node *ptr;
        ptr = *phead;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void display(Node **phead)
{
    Node *ptr = *phead;
    while (ptr != NULL)
    {
        printf("%d,", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    Node *head;
    int data;
    head = NULL;
    int n;
    printf(":::Enter your choice:::\n");
    printf("1. Enter Data\t 2. Display Linked List\t 3. Exit Terminal\n");
    printf("Your choice: ");
    scanf("%d", &n);
    do
    {
        switch (n)
        {
        case 1:
            printf("Enter the Element:");
            scanf("%d", &data);
            if(data==-999)
            {
                n=2;
                break;
            }
            append(&head, data);
            break;

        case 2:
            display(&head);
            n=3;
            break;

        case 3:
            printf(":::THE END:::\n");
            break;

        default:
            printf("...Wrong Choice! Please enter a correct choice....\n");
            break;
        }
    } while (n != 3);
    return 0;
}