//toupper from ctype using ascii

#include <stdio.h>
#include <string.h>

char _toupper(char c);

int main(void)
{
    char s[] = "hello, WorlD";
    printf("Before: %s\n", s);
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c",_toupper(s[i]));
        
    }
    return 0;
}

char _toupper(char c){
    if (c >= 'a' && c <= 'z')
    { // remember: ascii
        // change s[i] to uppercase
        // printf("%c", s[i] - 32);
        return c - ('a' - 'A');
    }
    else
    {
        return c;
    }
}