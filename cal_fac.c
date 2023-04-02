#include<stdio.h>
int main()
{
    int n,i,pro=1;
    printf("Enter the number to get the factorial of : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        pro=pro*i;
    }
    printf("The factorial of %d! is : %d",n,pro);
    return 0;
}