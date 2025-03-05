#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get user input name
    string name = get_string("What's your name? ");

    // print Hello, "name"
    printf("hello, %s", name);

    printf("\n");
}
