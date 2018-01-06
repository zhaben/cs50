//mario less

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    //prompt and validate user input
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    //draw the half pyramid
    for (int i = 0; i < n; i++)
    {
        //print spaces
        for (int z = n - 1; z > i; z--)
        {
            printf(" ");
        }

        //print hashes
        for (int m = -2; m < i; m++)
        {
            printf("#");
        }

        //print new line
        printf("\n");
    }
}