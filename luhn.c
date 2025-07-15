#include <stdio.h>

int main(void)
{

    long long int number;
    scanf("%lld", &number);

    long long int original = number; // saves an original copy of the number
    int position = 0;
    int sum = 0;
    int digit;
    int product;

    // Luhn's algorithm
    while (number > 0)
    {
        digit = number % 10;
        if (position % 2 == 1)
        {
            product = digit * 2;

            if (product > 9)
            {
                product = (product / 10) + (product % 10);
            }
            sum = sum + product;
        }
        else
        {
            sum = sum + digit;
        }
        number = number / 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID SUM\n");
        return 0;
    }
    number = original;

    int length = 0;
    while (number > 0)
    {
        number = number / 10;
        length++;
    }

    long long int first_two = original;

    while (first_two >= 100)
        first_two = first_two / 10;

    int first_one = first_two / 10;

    // verificate
    if ((first_two == 34 || first_two == 37) && length == 15)
        printf("AMEX\n");
    else if ((
                 first_two == 51 || first_two == 52 || first_two == 53 ||
                 first_two == 54 || first_two == 55) &&
             length == 16)
        printf("MASTERCARD\n");
    else if (first_one == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");
}