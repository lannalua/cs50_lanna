/*
 * Objective: This program calculates the readability of a text using the
 * Coleman-Liau index. The index is designed to output a U.S.
 * grade level required to understand the text.
 *
 * Input: a string of text from standard input.
 *
 * Output: calculated grade level, such as "Grade 5" or "Before Grade 1".
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_letters(char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
            count++;
    }
    return count;
}

int count_words(char *str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(char *str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    char *string = malloc(1000 * sizeof(char));
    if (string == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Count the number of letters, words, and sentences in the text
    fgets(string, 1000, stdin);

    int letters = count_letters(string);
    int words = count_words(string);
    int sentences = count_sentences(string);

    int index;
    float L, S;
    L = ((float) letters / words) * 100;
    S = ((float) sentences / words) * 100;

    // Compute the Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index >= 16)
        printf("Grade 16+\n",index);
    else if (index <= 1)
    {
        printf("Before Grade 1\n", index);
    }
    else
        printf("Grade %d\n", index);
    
    
    free(string);
}
