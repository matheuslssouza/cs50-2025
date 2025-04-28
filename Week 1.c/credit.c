#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number = get_long("Number: ");
    int count = 0;
    int sum = 0;
    int is_alternate = 0;
    long card_number_temp = card_number;
    long type_card;

    while (card_number_temp > 0)
    {
        int digit = card_number_temp % 10;

        if (is_alternate)
        {
            digit *= 2;
            sum += (digit > 9) ? (digit / 10) + (digit % 10) : digit;
        }
        else
        {
            sum += digit;
        }

        card_number_temp /= 10;
        is_alternate = !is_alternate;
        count++;
    }

    if (sum % 10 == 0)
    {
        for (int x = 0; count - 2 > x; x++)
        {
            card_number /= 10;
            type_card = card_number;
        }

        if (((type_card == 34) || (type_card == 37)) && (count == 15))
        {
            printf("AMEX\n");
        }
        else if (((type_card >= 51) && (type_card <= 55)) && (count == 16))
        {
            printf("MASTERCARD\n");
        }
        else if (((type_card >= 40) && (type_card <= 49)) && ((count == 13) || (count == 16)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
        return 0;
    }
    printf("INVALID\n");
}