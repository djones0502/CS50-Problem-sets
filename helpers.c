#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float bufferred = 0;
            float buffergreen = 0;
            float bufferblue = 0;
            float average;

            bufferred = image[i][j].rgbtRed;
            buffergreen = image[i][j].rgbtGreen;
            bufferblue = image[i][j].rgbtBlue;

            average = (bufferred + buffergreen + bufferblue) / 3;
            int roundedav = (int) round(average);

            image[i][j].rgbtRed = roundedav;
            image[i][j].rgbtGreen = roundedav;
            image[i][j].rgbtBlue = roundedav;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiared = 0;
            float sepiagreen = 0;
            float sepiablue = 0;

            sepiared = (image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) +
                       (image[i][j].rgbtBlue * 0.189);
            sepiagreen = (image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) +
                         (image[i][j].rgbtBlue * 0.168);
            sepiablue = (image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) +
                        (image[i][j].rgbtBlue * 0.131);

            int sepredro = (int) round(sepiared);
            int sepgreenro = (int) round(sepiagreen);
            int sepbluero = (int) round(sepiablue);

            if (sepredro > 255)
            {
                sepredro = 255;
            }

            if (sepgreenro > 255)
            {
                sepgreenro = 255;
            }

            if (sepbluero > 255)
            {
                sepbluero = 255;
            }

            image[i][j].rgbtRed = sepredro;
            image[i][j].rgbtGreen = sepgreenro;
            image[i][j].rgbtBlue = sepbluero;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;

            temp = image[i][j];

            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float averagered = 0;
            float averagegreen = 0;
            float averageblue = 0;
            int count = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int n = i + k;
                    int m = j + l;

                    if (n >= 0 && n < height && m >= 0 && m < width)
                    {
                        averagered += image[n][m].rgbtRed;
                        averagegreen += image[n][m].rgbtGreen;
                        averageblue += image[n][m].rgbtBlue;
                        count++;
                    }
                }
            }

            int avgred = (int) round(averagered / count);
            int avggreen = (int) round(averagegreen / count);
            int avgblue = (int) round(averageblue / count);

            buffer[i][j].rgbtRed = avgred;
            buffer[i][j].rgbtGreen = avggreen;
            buffer[i][j].rgbtBlue = avgblue;
        }
    }

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = buffer[k][l].rgbtRed;
            image[k][l].rgbtGreen = buffer[k][l].rgbtGreen;
            image[k][l].rgbtBlue = buffer[k][l].rgbtBlue;
        }
    }
    return;
}
