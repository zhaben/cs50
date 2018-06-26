//caesar, implement a program that encrypts messages using Caesar’s cipher
//ZhaBen

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])   //array of string
{

    //if the number of arguments in the command line is two
    if (argc != 2)
    {
        printf("Try again.");
        return 1;
    }
    //get plain text
    char *plaintext = get_string("plaintext: ");

    //turn the command line string argument into an integer
    int key = atoi(argv[1]);
    printf("ciphertext: ");

    //interate through each letter of the string
    for (int i = 0, j = strlen(plaintext); i < j; i++)
    {
        //if it's a letter
        if (isalpha(plaintext[i]))
        {
            //preserving the case
            if (isupper(plaintext[i]))
            {
                printf("%c", plaintext[i] = toupper(((plaintext[i] - 'A' + key) % 26) + 'A'));
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", plaintext[i] = tolower(((plaintext[i] - 'a' + key) % 26) + 'a'));
            }
        }
        //if not a letter
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

