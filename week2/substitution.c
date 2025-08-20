/*
    Substitution Cipher Program

    Objective:
    Encrypt a plaintext string using a substitution cipher with a user-provided 26-letter key.

    Input:
    - A single command-line argument: the cipher key (26 unique alphabetic characters).
    - User input: a plaintext string to be encrypted.

    Output:
    - The encrypted ciphertext string, printed to the console.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char map[26][2];

// function to apply Caesar cipher to a string using the given map
char *rotate(char *c)
{
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (isupper(c[i]))
        {
            int index = c[i] - 'A';
            c[i] = map[index][1];
        }
        // uppercase letter
        if (islower(c[i]))
        {
            int index = c[i] - 'a';
            c[i] = tolower(map[index][1]);
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

int letter_once(char *c)
{
    int checked[26] = {};

    for (int i = 0; c[i] != '\0'; i++)
    {
        if (!isalpha(c[i]))
            return 0;

        int index = toupper(c[i]) - 'A'; // 0-25

        if (checked[index])
            return 0;
        checked[index] = 1;
    }
    return 1;
}

void mapping_key(char key[26])
{
    for (int i = 0; i < 26; i++)
    {
        map[i][0] = 'A' + i;
        map[i][1] = toupper(key[i]);
    }
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

    // Make sure program was run with only alphabetic character
    if (only_digits(argv[1]))
    {
        printf("ERROR: To run the follow code you need to pass only alphabetic character");
        return 1;
    }

    // Ensure the key is 26 unique alphabetic characters
    if (strlen(argv[1]) != 26 || !letter_once(argv[1]))
    {
        printf("ERROR: To run the follow code you need to pass a sequence of 26 diferents alphabetic character");
        return 1;
    }

    char map_key[27];
    strcpy(map_key, argv[1]);

    // build the map
    mapping_key(map_key);

    char *plaintext = malloc(1000 * sizeof(char));

    printf("plaintext: ");
    scanf("%s", plaintext);

    // print the encrypted key
    printf("cyphentext: %s", rotate(plaintext));

    free(plaintext);
    return 0;
}