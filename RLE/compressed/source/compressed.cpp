#include "compressed.h"

#include <stdio.h>
#include <stdint.h>


static int read_sequence(int next_symbol, uint8_t *count, FILE *fp);

void comp_file(FILE *fp, FILE *c_fp)
{
    int next_symbol = getc(fp);
    int last_symbol = next_symbol;
    while ( next_symbol != EOF )
    {
        uint8_t count = 0;
        last_symbol = next_symbol;
        next_symbol = read_sequence(next_symbol, &count, fp);
        fputc(count, c_fp);
        fputc((uint8_t)last_symbol, c_fp);
    }
}

static int read_sequence(int next_symbol, uint8_t *count, FILE *fp)
{
    int last_symbol = next_symbol;
    while ( last_symbol == next_symbol && *count < 255)
    {
        last_symbol = next_symbol;
        next_symbol = getc(fp);
        *count += 1;
    }
    return next_symbol;
}


