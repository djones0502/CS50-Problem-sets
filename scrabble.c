#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // create letter library

    int one[20] = {'A', 'a', 'E', 'e', 'I', 'i', 'L', 'l', 'N', 'n',
                   'O', 'o', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u'};
    int two[4] = {'D', 'd', 'G', 'g'};
    int three[8] = {'B', 'b', 'C', 'c', 'M', 'm', 'P', 'p'};
    int four[10] = {'F', 'f', 'H', 'h', 'V', 'v', 'W', 'w', 'Y', 'y'};
    int five[2] = {'K', 'k'};
    int eight[4] = {'J', 'j', 'X', 'x'};
    int ten[4] = {'Q', 'q', 'Z', 'z'};

    // get input from player 1 and 2

    string wordpl1 = get_string("Player1: ");
    string wordpl2 = get_string("Player2: ");

    // go through each character of player 1

    int sumpl1;

    for (int i = 0; i < strlen(wordpl1); i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (wordpl1[i] == one[j])
            {
                sumpl1 = sumpl1 + 1;
            }
        }
        for (int a = 0; a < 4; a++)
        {
            if (wordpl1[i] == two[a])
            {
                sumpl1 = sumpl1 + 2;
            }
        }
        for (int b = 0; b < 8; b++)
        {
            if (wordpl1[i] == three[b])
            {
                sumpl1 = sumpl1 + 3;
            }
        }
        for (int c = 0; c < 10; c++)
        {
            if (wordpl1[i] == four[c])
            {
                sumpl1 = sumpl1 + 4;
            }
        }
        for (int d = 0; d < 2; d++)
        {
            if (wordpl1[i] == five[d])
            {
                sumpl1 = sumpl1 + 5;
            }
        }
        for (int e = 0; e < 4; e++)
        {
            if (wordpl1[i] == eight[e])
            {
                sumpl1 = sumpl1 + 8;
            }
        }
        for (int f = 0; f < 4; f++)
        {
            if (wordpl1[i] == ten[f])
            {
                sumpl1 = sumpl1 + 10;
            }
        }
    }
    printf("%i", sumpl1);

    // go through each character of player 2

    int sumpl2;

    for (int i = 0; i < strlen(wordpl2); i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (wordpl2[i] == one[j])
            {
                sumpl2 = sumpl2 + 1;
            }
        }
        for (int a = 0; a < 4; a++)
        {
            if (wordpl2[i] == two[a])
            {
                sumpl2 = sumpl2 + 2;
            }
        }
        for (int b = 0; b < 8; b++)
        {
            if (wordpl2[i] == three[b])
            {
                sumpl2 = sumpl2 + 3;
            }
        }
        for (int c = 0; c < 10; c++)
        {
            if (wordpl2[i] == four[c])
            {
                sumpl2 = sumpl2 + 4;
            }
        }
        for (int d = 0; d < 2; d++)
        {
            if (wordpl2[i] == five[d])
            {
                sumpl2 = sumpl2 + 5;
            }
        }
        for (int e = 0; e < 4; e++)
        {
            if (wordpl2[i] == eight[e])
            {
                sumpl2 = sumpl2 + 8;
            }
        }
        for (int f = 0; f < 4; f++)
        {
            if (wordpl2[i] == ten[f])
            {
                sumpl2 = sumpl2 + 10;
            }
        }
    }
    printf("%i", sumpl2);

    // Determin which player has won

    if (sumpl1 > sumpl2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (sumpl2 > sumpl1)
    {
        printf("Player 2 Wins!\n");
    }
    else if (sumpl2 == sumpl1)
    {
        printf("Tie!\n");
    }
}
