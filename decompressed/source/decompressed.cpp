#include "decompressed.h"

#include <stdio.h>

void decomp_file(FILE *fp, FILE *c_fp)
{
    int symbol = 0;
    int count  = 0;
    while (count != EOF)
    {
        count = getc(c_fp);
        symbol = getc(c_fp);
        for ( int i = 0; i < count; ++i)
            fprintf(fp, "%c", (char)symbol);
    }
}



