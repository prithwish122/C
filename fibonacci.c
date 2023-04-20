/* Fibonacci series using array upto 'n' elements. */
#include <stdio.h>
int main()
{
    int n, a[50];
    int i;
    printf("Enter the number of elements required: ");
    scanf("%d", &n);
    a[0] = 0;
    a[1] = 1;
    for (i = 2; i < n; i++)
    {
        a[i] = a[i - 2] + a[i - 1];
    }
    printf("The fibonacci series upto %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}