/*Enter two matrices and add them in a separate matrix.*/
#include <stdio.h>
int main()
{
    int a[20][20], b[20][20], c[20][20];
    int i, j, r;
    printf("Enter the number of rows and columns of a square matrices: ");
    scanf("%d", &r);
    printf("Enter the elements of the matrix A:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the matrix B:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Adding two matrices....\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Displaying the final sum in matrix format:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}