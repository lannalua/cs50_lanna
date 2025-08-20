/*
    Caesar Cipher Program

    Objective:
    Encrypt a plaintext string using the Caesar cipher algorithm with a user-provided integer key.

    Input:
    - A single command-line argument: the cipher key (an integer).
    - User input: a plaintext string to be encrypted.

    Output:
    - The encrypted ciphertext string, printed to the console.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// function to apply Caesar cipher to a string using the given key
char *rotate(char *c, int key)
{
    // int size = strlen(c);

    for (int i = 0; c[i] != '\0'; i++)
    {
        // uppercase letter
        if (c[i] >= 65 && c[i] <= 90)
        {
            if (c[i] + key <= 90)
                c[i] = c[i] + key;
            else
            {
                int aux = c[i] + key - 90;
                c[i] = 64 + aux;
            }
        }
        // llowercase letter
        if (c[i] >= 97 && c[i] <= 122)
        {
            if (c[i] + key <= 122)
                c[i] = c[i] + key;
            else
            {
                int aux = c[i] + key - 122;
                c[i] = 96 + aux;
            }
        }
    }

    return c;
}

// Function to check if a string contains only digits
int only_digits(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}
int main(int argc, char *argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("ERROR: To run the follow code you need to pass a single command-line argument\n");
        printf("Usage: ./caesar key");
        return 1;
    }

    // Make sure program was run with only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    int key = atoi(argv[1]);

    char *plaintext = malloc(1000 * sizeof(char));

    printf("plaintext: ");
    scanf("%s", plaintext);

    // print the encrypted key
    printf("cyphentext: %s", rotate(plaintext, key));

    free(plaintext);
    return 0;
}