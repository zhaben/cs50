//Vigenere, implement a program that encrypts messages using Vigenère’s cipher
//ZhaBen

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])   //array of string
{
    //if the number of arguments in the command line is two, return 1
    if (argc != 2)
    {
        printf("The number of arguments in the command line are not exactly 2.\n");
        return 1;
    }

    //store the string into a variable
    char *key = argv[1];

    //interate through each letter of the string to confirm that it is alphabetical
    for (int k = 0; k < strlen(key); k++)
    {
        if (!isalpha(key[k]))
        {
            printf("Key is not an alphabetical character\n");
            return 1;
        }
    }

    //get plain text
    char *plaintext = get_string("plaintext: ");

    //iterate through plaintext and print ciphertext
    printf("ciphertext: ");
    for (int i = 0, klen = 0, j = strlen(plaintext); i < j; i++)
    {
        //if alphabetical, rotate
        if (isalpha(plaintext[i]))
        {
            //preserve the case
            if (isupper(plaintext[i]))
            {
                printf("%c", plaintext[i] = ((plaintext[i] - 'A' + (toupper(key[klen]) - 'A')) % 26) + 'A');
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", plaintext[i] = ((plaintext[i] - 'a' + (tolower(key[klen]) - 'a')) % 26) + 'a');
            }
            klen = (klen + 1) % strlen(key);    //key cannot increment at the same rate as the plaintext
        }
        //if non-alphabetical, do not rotate
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}


