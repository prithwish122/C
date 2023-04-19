//Calculate the given problem: 1+x+((x^2)/2!)+((x^3)/3!)+.....+((x^n)/n!).
#include<stdio.h>
#include<math.h>
int main()
{
    float n,x,num,den=1,sum=1;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("Enter the value of the last digit of the series: ");
    scanf("%f",&n);
    for(int i=1;i<=n;i++)
    {
    num=pow(x,i);//Calculation of the numerator part.
    for(int k=1;k<=i;k++)
    {
        den=den*k;//Calculation of denominator part.
    }
    printf("%f\n",num/den);
    sum=sum+(num/den);
    }
    printf("The result of the summation is: %f",sum);
    return 0;
}