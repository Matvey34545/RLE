#include "decompressed.h"

#include <stdio.h>

enum ErrorDecompression
{
    ERROR_DECOMPRESSION_NO_ERROR = 0,
    ERROR_DECOMPRESSION_NO_FILE  = 1
};

int main(int argc, char *argv[])
{
    const char *compressed_file = *(argv + 1);
    const char *file = *(argv + 2);
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
        return ERROR_DECOMPRESSION_NO_FILE;

    FILE *c_fp = fopen(compressed_file, "rb");
    if (c_fp == NULL)
        return ERROR_DECOMPRESSION_NO_FILE;

    decomp_file(fp, c_fp);
    fclose(fp);
    fclose(c_fp);
}
