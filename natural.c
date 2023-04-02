#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter the last number of the digit you want to add: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    printf("The sum of the first %d natural numbers is %d",n,sum);
    return 0;
}