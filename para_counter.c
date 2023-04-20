/*Program to count lines, words and characters in a text.*/

#include <stdio.h>
#include <string.h>
int main()
{
    int len, i, word = 0, line = 0;
    char t[500];
    printf("Enter a text:\n ");
    gets(t);
    len = strlen(t);
    for (i = 0; i < len; i++)
    {
        if (t[i] == ' ')  // if (t[i] == '\0') is not working.
        {
            word++;
        }
        if (t[i] == '.')
        {
            line++;
        }
    }
    printf("The number of characters= %d,\nThe number of lines= %d, \nThe number of words=%d", len, line, word);
    return 0;
}