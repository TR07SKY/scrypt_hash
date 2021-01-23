#include <stdio.h>
#include <inttypes.h>

#include "crypto/scrypt.h"
#include "utils/util.h"

int main(void)
{
    const char* inputhex = "020000004c1271c211717198227392b029a64a7971931d351b387bb80db027f270411e398a07046f7d4a08dd815412a8712f874a7ebf0507e3878bd24e20a3b73fd750a667d2f451eac7471b00de6659";
    std::vector<unsigned char> inputbytes = ParseHex(inputhex);

    uint256 scrypthash;

    const uint32_t N = 1024;
    const uint32_t r = 1;
    const uint32_t p = 1;

    char sp_size[63 + (128 * r * p) + (256 * r + 64) + (128 * r * N)];

    scrypt_custom_256((const char*)&inputbytes[0], BEGIN(scrypthash), sp_size, N, r, p);

    printf("%lx\n", scrypthash);

	return 0;
}
