#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    // prompt user for text
    string text = get_string("Text: ");

    // loop through Text to find out how many letters there are
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            letters = letters + 1;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            letters = letters + 1;
        }
    }

    // loop through text to find out how many words the text has
    int words = 0;

    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == 32)
        {
            words = words + 1;
        }
    }

    // add 1 for end of text
    words = words + 1;

    // loop through text to find how many sentences the text hast
    int sentences = 0;

    for (int h = 0; h < strlen(text); h++)
    {
        if (text[h] == 33 || text[h] == 46 || text[h] == 63)
        {
            sentences = sentences + 1;
        }
    }

    // calculate average number of letters/sentences per 100 Words
    float l;
    float s;

    l = ((float) letters / (float) words) * 100;
    s = ((float) sentences / (float) words) * 100;

    // input in to formula
    float cli;

    cli = 0.0588 * l - 0.296 * s - 15.8;

    // round float to an intiger
    int rcli;

    rcli = round(cli);

    // determin reading level by rcli

    if (rcli > 16)
    {
        printf("Grade 16+\n");
    }
    else if (rcli < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rcli);
    }
}
