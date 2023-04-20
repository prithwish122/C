/*Accept and display numbers in a 2D array matrix.*/
#include <stdio.h>
int main()
{
    int a[20][20];
    int i, j, r, c;
    printf("Enter the row and column of the matrix: ");
    scanf("%d%d", &r, &c);
    printf("Enter the elements of the matrix: ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Displaying the elements in matrix format:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}