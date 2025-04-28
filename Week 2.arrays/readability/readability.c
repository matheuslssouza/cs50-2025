#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float calcLetters(string text)
{
    int letters = 0;

    for (int i = 0, textSize = strlen(text); i < textSize; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return (float) letters;
}

float calcWords(string text)
{
    int words = 0;

    for (int i = 0, textSize = strlen(text); i < textSize; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    return (words + 1);
}

float calcSentences(string text)
{
    int sentences = 0;

    for (int i = 0, textSize = strlen(text); i < textSize; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return (float) sentences;
}

int main(int argc, string argv[])
{

    string text = get_string("Text: ");

    // Calcular L - Numero de letras por 100 palavras
    float L = (calcLetters(text) / calcWords(text)) * 100;
    float S = (calcSentences(text) / calcWords(text)) * 100;

    float index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    if (index >= 2.0 && index < 16)
    {
        printf("Grade %i\n", (int) index);
    }
    if (index >= 16.0)
        printf("Grade 16+\n");
}