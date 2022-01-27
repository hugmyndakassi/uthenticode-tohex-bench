#include <cstdio>
#include <cinttypes>

bool reader(size_t const size)
{
    FILE* frand = fopen("/dev/urandom", "rb");
    if (!frand)
        return false;
    FILE* fdevnull = fopen("/dev/null", "w");
    if (!fdevnull)
        return false;
    size_t pos = 0;
    constexpr size_t const chunksize = 0x10000;
    uint8_t buf[chunksize]{};
    while(pos < size)
    {
        if (1 != fread(buf, chunksize, 1, frand))
        {
            (void)fclose(frand);
            (void)fclose(fdevnull);
            return false;
        }
        auto const str = tohex(buf, chunksize);
        if (1 != fwrite(str.c_str(), str.length(), 1, fdevnull))
        {
            (void)fclose(frand);
            (void)fclose(fdevnull);
            return false;
        }
        pos += chunksize;
    }
    (void)fclose(frand);
    (void)fclose(fdevnull);
    return true;
}

constexpr size_t const amount_to_read = 0x10000000; // 256 MiB

