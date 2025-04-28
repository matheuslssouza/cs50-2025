#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string encryptText(string plainText, string argv[])
{
    for (int i = 0, textSize = strlen(plainText), index = 0; i < textSize; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                index = plainText[i] - 'a';
                plainText[i] = tolower(argv[1][index]);
            }
            else
            {
                index = plainText[i] - 'A';
                plainText[i] = toupper(argv[1][index]);
            }
        }
    }

    return plainText;
}

bool isValidKey(string key)
{
    int letterCount = 0;

    for (int i = 0, keyLength = strlen(key); i < keyLength; i++)
    {
        if (isalpha(key[i]))
        {
            letterCount++;
        }
    }
    return letterCount == 26;
}

bool hasRepeatedChars(string key)
{
    for (int i = 0, keyLength = strlen(key); i < keyLength; i++)
    {
        for (int j = i + 1; j < keyLength; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return true; // Encontrou caracteres repetidos
            }
        }
    }
    return false; // Não há caracteres repetidos
}

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];

        if (isValidKey(key) && !hasRepeatedChars(key))
        {
            string plainText = get_string("plaintext: \n");
            printf("ciphertext: %s\n", encryptText(plainText, argv));
            return 0;
        }
        else
        {
            printf("Key must contain 26 unique alphabetic characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}