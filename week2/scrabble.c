#include <stdio.h>
#include <string.h>
#include <ctype.h>

char letters[26][2];

char touppercase(char *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        str[i] = toupper(str[i]);
    }

    return str[n];
}

int calculapontos(char *str, int n)
{
    int pontos = 0;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (letters[i][0] == (int)str[j])
                pontos = pontos + letters[i][1];
        }
    }

    return pontos;
}

int main()
{
    // inicializando matriz de letters[letra,ponto]

    //letras maiusculas do alfabeto usando ascii
    for (int i = 0; i < 26; i++)
        letters[i][0] = (int)65 + i;

    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0; i < 26; i++)
    {
        letters[i][1] = points[i];
    }
    //------------------------------------------

    //player1
    char word1[100]; 

    printf("Player 1: ");
    scanf(" %s",word1);

    int length = strlen(word1);
    touppercase(word1, strlen(word1));

    // calculando os pontos
    int player1 = calculapontos(word1, length);
    //------------------------------------------

    //player2
    char word2[100];

    printf("Player 2: ");
    scanf(" %s", word2);

    length = strlen(word2);
    touppercase(word2, strlen(word2));

    // calculando os pontos
    int player2 = calculapontos(word2, length);

    if (player1>player2)
        printf("Player 1 wins!\n");
    else if (player2>player1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

    return 0;
}