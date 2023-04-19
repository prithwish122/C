//Find the smallest of three numbers entered by the user.
#include<stdio.h>
int main()
{
    int n1,n2,n3,min;
    printf("Enter any three digits: ");
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    min=n1;
    if(n2<min)
    {
        min=n2;
    }
    if(n3<min)
    {
        min=n3;
    }
    printf("The smallest of all three numbers is %d",min);
    return 0;
}