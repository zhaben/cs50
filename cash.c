//Cash, modulo
//ZhaBen

#import <stdio.h>
#import <cs50.h>
#import <math.h>

int main(void)
{
    float n;
    int i = 0;

    //prompt user for change, value must be positive
    do
    {
        n = get_float("Change: ");
    }
    while (n < 0);

    //convert to dollars
    int change = roundf(n * 100);

    //use the largest coin possible
    if (change % 25 >= 0)
    {
        while (change >= 25)
        {
            change -= 25;
            i++;
        }
    }

    if (change % 10 >= 0)
    {
        while (change >= 10)
        {
            change -= 10;
            i++;
        }
    }

    if (change % 5 >= 0)
    {
        while (change >= 5)
        {
            change -= 5;
            i++;
        }
    }

    if (change % 1 >= 0)
    {
        while (change > 0)
        {
            change -= 1;
            i++;
        }
    }

    //print the final number of coins
    printf("%i\n", i);
}

