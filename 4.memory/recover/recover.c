#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE uint8_t
#define BLOCKS 512
#define SIZE_IDENTIFY_JPEG 3

const BYTE BEGIN_JPEG[SIZE_IDENTIFY_JPEG] = {0xff, 0xd8, 0xff};

int main(int argc, char *argv[])
{
    // Verificar argumento correto
    if (argc != 2)
    {
        printf("Usage: ./recover image.raw\n");
        return 1;
    }

    // Abrir arquivo de entrada
    FILE *image = fopen(argv[1], "rb");
    if (image == NULL)
    {
        printf("Image cannot be opened!\n");
        return 1;
    }

    BYTE buffer[BLOCKS];
    char fileName[8];
    int countFiles = 0;
    FILE *output = NULL;

    while (fread(buffer, BLOCKS, 1, image) == 1)
    {

        if (memcmp(buffer, BEGIN_JPEG, SIZE_IDENTIFY_JPEG) == 0 &&
            (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {

            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(fileName, "%03i.jpg", countFiles);
            output = fopen(fileName, "wb");
            if (output == NULL)
            {
                printf("Error creating file %s\n", fileName);
                fclose(image);
                return 1;
            }

            countFiles++;
        }

        if (output != NULL)
        {
            fwrite(buffer, BLOCKS, 1, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }
    fclose(image);

    return 0;
}