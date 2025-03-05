#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // user input for pyramid
    int hight;
    do
    {
        hight = get_int("How tall is the Pyramid? ");
    }
    while (hight < 1 || hight > 8);

    for (int length = 0; length < hight; length++)
    {
        for (int space = 0; space < hight - length - 1; space++)
        {
            printf(" ");
        }
        for (int hash = 0; hash <= length; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int hash2 = 0; hash2 <= length; hash2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
