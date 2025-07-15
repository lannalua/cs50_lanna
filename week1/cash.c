#include <stdio.h>

int main(void)
{
    int change;
    int result = 0;

    printf("Change owed: ");
    scanf("%d", &change);

    result += change / 25;
    change %= 25;

    result += change / 10;
    change %= 10;

    result += change / 5;
    change %= 5;

    result += change;

    printf("%d\n", result);

    return 0;
}
