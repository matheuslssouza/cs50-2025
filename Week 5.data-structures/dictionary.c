// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

unsigned int count_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char word_lower[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        word_lower[i] = tolower(word[i]);
    }
    word_lower[strlen(word)] = '\0'; // Adiciona o terminador nulo

    unsigned int index = hash(word_lower);
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(word_lower, ptr->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char read_word[LENGTH + 1];

    while (fscanf(file, "%s", read_word) != EOF)
    {

        node *list = malloc(sizeof(node));

        if (list == NULL)
        {
            return false;
        }

        strcpy(list->word, read_word);
        list->next = NULL;

        unsigned int index = hash(read_word);

        if (table[index] == NULL)
        {
            table[index] = list;
        }

        else
        {
            list->next = table[index];
            table[index] = list;
        }

        count_words++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *next_ptr = NULL;

        for (node *ptr = table[i]; ptr != NULL;)
        {
            next_ptr = ptr->next;
            free(ptr);
            ptr = next_ptr;
        }
    }
    return true;
}