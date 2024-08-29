#include "compressed.h"

#include <stdio.h>

enum ErrorCompression
{
    ERROR_COMPRESSION_NO_ERROR = 0,
    ERROR_COMPRESSION_NO_FILE  = 1
};

int main(int argc, char *argv[])
{
    const char *file = *(argv + 1);
    const char *compressed_file = *(argv + 2);
    FILE *fp = fopen(file, "r");
    if ( fp == NULL )
        return ERROR_COMPRESSION_NO_FILE;

    FILE *c_fp = fopen(compressed_file, "wb");
    if ( c_fp == NULL )
        return ERROR_COMPRESSION_NO_FILE;

    comp_file(fp, c_fp);
    fclose(fp);
    fclose(c_fp);
}
