//Centigrade and Farenheit conversion using switch case.
#include<stdio.h>
#include<string.h>
int main()
{
    float t,c,f;
    int choice;
    printf("Enter the temperature you want to convert: ");
    scanf("%f",&t);
    printf("Enter your choice to convert the temperature to,\n 1:For farenheit56 or 2:For centigrade :- ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        f=((t*9)/5)+32;
        printf("\nThe temperature in farenheit %f F\n",f);
        break;
    case 2:
        c=(5*(t-32))/9;
        printf("\nThe temperature in celcius %f C\n",c);
        break;
    
    default:
        printf("Invalid input");
        break;
    }
    return 0;
}