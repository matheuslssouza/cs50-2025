#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE grayValue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grayValue = (BYTE) round(
                (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = grayValue;
            image[i][j].rgbtRed = grayValue;
            image[i][j].rgbtGreen = grayValue;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = (int) round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                              .189 * image[i][j].rgbtBlue);
            green = (int) round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                .168 * image[i][j].rgbtBlue);
            blue = (int) round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                               .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = red > 255 ? 255 : (BYTE) red;
            image[i][j].rgbtGreen = green > 255 ? 255 : (BYTE) green;
            image[i][j].rgbtBlue = blue > 255 ? 255 : (BYTE) blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float count = 0.0;

            for (int linha_quadrado = i - 1; linha_quadrado <= i + 1; linha_quadrado++)
            {
                for (int coluna_quadrado = j - 1; coluna_quadrado <= j + 1; coluna_quadrado++)
                {
                    if (linha_quadrado >= 0 && linha_quadrado < height && coluna_quadrado >= 0 &&
                        coluna_quadrado < width)
                    {
                        sumRed += copy[linha_quadrado][coluna_quadrado].rgbtRed;
                        sumGreen += copy[linha_quadrado][coluna_quadrado].rgbtGreen;
                        sumBlue += copy[linha_quadrado][coluna_quadrado].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = (int) round(sumRed / count);
            image[i][j].rgbtGreen = (int) round(sumGreen / count);
            image[i][j].rgbtBlue = (int) round(sumBlue / count);
        }
    }

    return;
}