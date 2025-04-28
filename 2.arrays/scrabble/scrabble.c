#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calcPoints(int points[], string word)
{
    int summ = 0;
    for (int x = 0, size = strlen(word); x < size; x++)
    {
        if (word[x] >= 'A' && word[x] <= 'Z')
        {
            int letter = word[x] - 'A';
            summ += points[letter];
        }
    }
    return summ;
}

string uppercase(string word)
{
    for (int i = 0, size = strlen(word); i < size; i++)
    {
        word[i] = toupper(word[i]);
    }
    return word;
}

int main(int argc, string argv[])
{

    // Create the points map in array
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Ask word for player 1 and player 2 , just one word.
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int p1 = calcPoints(points, uppercase(player1));
    int p2 = calcPoints(points, uppercase(player2));

    if (p1 == p2)
    {
        printf("Tie!\n");
    }
    else if (p1 > p2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}