#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //User Input for Card number
    long number;
    do
    {
        number = get_long ("Number: ");
    }
    while (number <= 0);

    //checking if card number is valid and which card it is


    if (number >= 3400000000000000 && number <= 3799999999999999)
        {
            printf("AMEX\n");
        }
    else if (number >= 5100000000000000 && number <= 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
    else if (number >= 4000000000000000 && number <= 4999999999999999)
        {
            printf("VISA\n");
        }
    else
        {
            printf("INVALID\n");
        }


























}
