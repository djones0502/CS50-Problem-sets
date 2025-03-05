#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    // ask user for item value
    do
    {
        change = get_int("Change owed? ");
    }
    while (change <= 0);

    int changerest;

    int change25 = change / 25;
    int changerest25 = change25 * 25;
    changerest = change - changerest25;

    int change10 = changerest / 10;
    int changerest10 = change10 * 10;
    changerest = changerest - changerest10;

    int change5 = changerest / 5;
    int changerest5 = change5 * 5;
    changerest = changerest - changerest5;

    int change1 = changerest / 1;
    int changerest1 = change1 * 1;
    changerest = changerest - changerest1;

    int cashrest = change25 + change10 + change5 + change1;
    printf("%i", cashrest);
    printf("\n");
}
