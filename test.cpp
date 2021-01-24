#include <stdio.h>
#include <inttypes.h>

#include "crypto/scrypt.h"
#include "utils/util.h"

#define STR_LEN 160

int main(void)
{
    unsigned char str[STR_LEN + 1] = {0};
    const char* hex_digits = "0123456789abcdef";

    srand(time(NULL));

    for(int i = 0 ; i < STR_LEN ; i++ )
        str[i] = hex_digits[(rand() % 16)];

    uint256 scrypthash;

    const uint32_t N = 1024;
    const uint32_t r = 2048;
    const uint32_t p = 1;

    char* sp_size = (char*)malloc(sizeof(char)*(63 + (128 * r * p) + (256 * r + 64) + (128 * r * N)));
    //unsigned char sp_size[63 + (128 * r * p) + (256 * r + 64) + (128 * r * N)];

    printf("Random hex: %s\n", str);
    printf("N: %u\n", N);
    printf("r: %u\n", r);
    printf("p: %u\n", p);
    printf("Scratchpad size: %lu\n", 63 + (128 * r * p) + (256 * r + 64) + (128 * r * N));
    printf("Memory usage: %u MB\n", ((128 * N * r * p) / 1024) / 1024);

    scrypt_custom_256((const char*)&str[0], BEGIN(scrypthash), sp_size, N, r, p);

    printf("Scrypt output: %x\n", scrypthash);

    free(sp_size);
	return 0;
}
