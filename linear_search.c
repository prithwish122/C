/* Search an integer using linear search.*/
#include <stdio.h>
int main()
{
    int a[100];
    int i, n, item, flag;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element you want to search:\n");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            printf("The element is present at %d position", i + 1);
            flag = 1;
        }
    }
    if (flag != 1)
        printf("The element is not present ");
    return 0;
}