#include <stdio.h>

int string_length(char *s);

int main(){

    char string[] = "Hello, world";
    printf("%d",string_length(string));
    
    return 0;

}

int string_length(char *s)
{
    int n = 0;
    while (s[n] != '\0'){
        n++;
    }
    return n;
}