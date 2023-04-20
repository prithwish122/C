/*Find the number of vowels and consonant present in the string. */
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0, len = 0, v = 0, c = 0;
    char s[30];
    printf(" Enter a string: ");
    gets(s);
    len=strlen(s);
   /* while (s[i] != '\0')
    {
        len++;
        i++;
    }*/
    for (i = 0; i <= len; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
        {
            v++;
        }
        else if (s[i] == '.'|| s[i] == ' ') // s[i] == '\0' is not working.
        {
            continue;
        }
        else
        {
            c++;
        }
    }
    printf("There are %d vowels and %d consonants are present in the string.\n", v, c);
    return 0;
}