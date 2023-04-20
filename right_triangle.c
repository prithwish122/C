/*Print right angled triangle using "*" */
#include <stdio.h>
int main()
{
    int n;
    int i, j;
    printf("Enter the number of rows of your triangle: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
