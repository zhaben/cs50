// Music: Convert musical notes to frequencies and synthesize songs
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator;
    int denominator;
    char tmp_num[2];
    char tmp_den[2];

    // Changes characters into strings and strings into integers to calclate the numerator
    tmp_num[0] = fraction[0];
    tmp_num[1] = '\0';
    tmp_den[0] = fraction[2];
    tmp_den[1] = '\0';
    numerator = atoi(tmp_num);
    denominator = atoi(tmp_den);

    // Converts fraction into an integer, returns only the numerator
    if (denominator == 2)
    {
        return numerator *= 4;
    }
    else if (denominator == 4)
    {
        return numerator *= 2;
    }
    else if (denominator == 1)
    {
        return numerator *= 8;
    }
    else
    {
        return numerator;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Take an input as a string a note and return its frequency in hertz as an int
    char    accidental;
    char    default_octave;
    float   f;
    int     i;
    char    newnote;
    char    octave;
    char    tmp_oct[2];

    // Starts at the default octave and frequency
    f = 440;
    default_octave = 4;

    // Parses notes from text file, identifying accidentals and octaves
    newnote = note[0];
    if (note[1] == '#' || note[1] == 'b')
    {
        accidental = note[1];
        octave = note[2];
    }
    else
    {
        octave = note[1];
    }

    // Converts an octave to an integer
    tmp_oct[0] = octave;
    tmp_oct[1] = '\0';
    i = atoi(tmp_oct);

    // Step 1: Implement octaves of A
    while (i != default_octave)
    {
        if (i < default_octave)
        {
            f = f / 2;
            i++;
        }
        else if (i > default_octave)
        {
            f = f * 2;
            i--;
        }
    }
    // Step 2: Support A# and Ab in those multiple octaves
    if (accidental == '#')
    {
        f = (f * pow(2, 1.0 / 12.0));
    }
    if (accidental == 'b')
    {
        f = (f / pow(2, 1.0 / 12.0));
    }

    // Step 3: Support All Notes
    switch (note[0])
    {
        case 'C' :
            f = f / pow(2, 9.0 / 12);
            break;
        case 'D' :
            f = f / pow(2, 7.0 / 12);
            break;
        case 'E' :
            f = f / pow(2, 5.0 / 12);
            break;
        case 'F' :
            f = f / pow(2, 4.0 / 12);
            break;
        case 'G' :
            f = f / pow(2, 2.0 / 12);
            break;
        case 'A' :
            f = f * pow(2, 0.0 / 12);
            break;
        case 'B' :
            f = f * pow(2, 2.0 / 12);
            break;
        default :
            return (0);
    }
    return (round(f));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // Interprets "\n" and "\r" as ""
    if (strncmp(s, "", 1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}