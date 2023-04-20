/*Program to accept and display the student records using "struct" structure. */
#include <stdio.h>
int main()
{
    int find;
    int i, flag = 0;
    struct student
    {
        int roll_no;
        char name[30];
        float marks;
    };
    struct student a[3];
    printf("\n:::Enter the data of the students:::\n");
    for (i = 0; i < 3; i++)
    {
        printf("Enter the name of student %d: ", i + 1);  
        //fgets(a[i].name,30,stdin); 
        scanf("%s", &a[i].name);//fgets and gets are working once only, need to find a better alternative.
        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &a[i].roll_no);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &a[i].marks);
        printf("\n");
    }
    printf("Enter a roll number to display:");
    scanf("%d", &find);
    for (i = 0; i < 3; i++)
    {
        if (find == a[i].roll_no)
        {
            printf("The roll number of the student is %d\n", a[i].roll_no);
            printf("The name of the student is ");
            puts(a[i].name);
            printf("The marks of the student is %f percent\n", a[i].marks); 
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Record not found");
    }
    return 0;
}