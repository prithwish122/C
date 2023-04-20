/*Maximum of the entered element using array.*/
#include <stdio.h>
int main()
{
    int n;
    int a[50];
    int i, max;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    printf("Enter %d elements one by one:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The greatest of all elements: ");
    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (max > a[i])
        {
            max = max;
        }
        else
        {
            max = a[i];
        }
    }
    printf("%d", max);
    return 0;
}
