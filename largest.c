//Find the largest of three numbers entered by the user.
#include<stdio.h>
int main()
{
    int n1,n2,n3,max;
    printf("Enter any three digits: ");
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    max=n1;
    if(n2>max)
    {
        max=n2;
    }
    if(n3>max)
    {
        max=n3;
    }
    printf("The largest of all three numbers is %d",max);
    return 0;
}