#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // return 1 if more or less than 1 command line argument
    if (argc > 2)
    {
        printf("Only one CLA allowed!\n");
        return 1;
    }
    else if (argc <= 1)
    {
        printf("Only one CLA allowed!\n");
        return 1;
    }

    // open File from CLA
    FILE *input = fopen(argv[1], "r");
    // check if input is correct, else return 1
    if (input == NULL)
    {
        printf("Something went wrong!\n");
        return 1;
    }

    unsigned char block[512];
    int counter = -1;
    char imgnum[999] = {0};
    FILE *img = NULL;

    // iterate through all files until Card is at the end
    while (fread(block, 512, 1, input) != 0)
    {
        // check if first 4 blocks are jpg header
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // if image is still open, close it
            if (img != NULL)
            {
                fclose(img);
            }
            // count how many jpeg files we have for image names
            counter++;
            // create new jpg file
            sprintf(imgnum, "%03i.jpg", counter);
            img = fopen(imgnum, "w");
            // if new jpg file is not opened return 1
            if (img == NULL)
            {
                return 1;
            }
            // write the block of the recovering image
            fwrite(block, 512, 1, img);
        }
        else
        {
            // else if file is open write next block to recovering file
            if (img != NULL)
            {
                fwrite(block, 512, 1, img);
            }
        }
    }
    // close input and img file and exit to not get any memory leaks
    fclose(input);
    fclose(img);
}
