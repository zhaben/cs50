//Mario, implement a program that prints out a double half-pyramid of a specified height
//ZhaBen

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
        //print spaces for left pyramid
        for (int m = n - 2; m >= i; m--)
        {
            printf(" ");
        }

        //print hashes for left pyramid
        for (int m = -1; m < i; m++)
        {
            printf("#");
        }

        //print gap
        printf("  ");

        //print hashes for right pyramid
        for (int m = -1; m < i; m++)
        {
            printf("#");
        }

        //print new line
        printf("\n");
    }
}