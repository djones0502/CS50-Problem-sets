// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t buffer[44];

    // read first 44 bytes from wav file
    fread(buffer, sizeof(uint8_t), 44, input);
    // copy 44 bytes to output file
    fwrite(buffer, sizeof(uint8_t), 44, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t sbuffer[0];
    int16_t sbuffere[0];

    while (fread(sbuffer, sizeof(int16_t), 1, input) != 0)
    {
        sbuffere[0] = sbuffer[0] * factor;
        fwrite(sbuffere, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
