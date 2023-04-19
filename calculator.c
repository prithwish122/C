//A simple calculator for division, addition, subtraction and multiplication.
#include<stdio.h>
int main()
{
float num1,num2;
float sum,sub,pro,quo;
printf("Enter two numbers ");
scanf("%f%f",&num1,&num2);
sum=num1+num2;
sub=num1>num2?num1-num2:num2-num1;
pro=num1*num2;
quo=num1>num2?num1/num2:num2/num1;
printf("The sum of the two digits are: %f, The subtraction of the two numbers are: %f, The multiplication of two numbers are: %f, The division of two numbers are: %f\n",sum,sub,pro,quo);
return 0;
}