/*Decimal to binary using array.*/
#include <stdio.h>
int main()
{
    int a[50], d;
    int i = 0, t;
    printf("Enter a decimal number: ");
    scanf("%d", &d);
    printf("Converting the number in binary....\n");
    t = d;
    while (d > 0)
    {
        if (d % 2 == 0)
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
        d = d / 2;
        i++;
    }
    printf("The binary value of  %d is ", t);
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}