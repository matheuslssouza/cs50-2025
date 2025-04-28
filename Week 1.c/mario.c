#include <cs50.h>
#include <stdio.h>

int main()
{

    int height;

    do
    {
        height = get_int("Insert a number between 1 and 8 \n");
    }
    while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++)
    {
        for (int space = 0; space < (height - row); space++)
        {
            printf(" ");
        }
        for (int hash_left = 0; hash_left < row; hash_left++)
        {
            printf("#");
        }
        printf("  ");

        for (int hash_right = 0; hash_right < row; hash_right++)
        {
            printf("#");
        }

        printf("\n");
    }
}