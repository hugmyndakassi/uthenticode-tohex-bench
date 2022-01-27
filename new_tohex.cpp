#include <string>

static inline std::string tohex(std::uint8_t const* buf, std::size_t len)
{
    constexpr static char lookup_table[0x10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (!buf || !len)
    {
        return {};
    }

    std::string hexstr;
    hexstr.reserve(len * 2); // each byte creates two hex digits

    for (auto i = 0; i < len; i++)
    {
        hexstr += lookup_table[buf[i] >> 4];
        hexstr += lookup_table[buf[i] & 0xF];
    }

    return hexstr;
}

#include "reader.inl"
#include <iostream>

int main()
{
    return reader(amount_to_read) ? 0 : 1;
}
