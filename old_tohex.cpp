#include <string>
#include <sstream>
#include <iomanip>

static inline std::string tohex(std::uint8_t const* buf, std::size_t len)
{
    if (buf == nullptr)
    {
        return {};
    }

    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0');

    for (std::size_t i = 0; i < len; ++i)
    {
        ss << static_cast<int>(buf[i]);
    }

    return ss.str();
}

#include "reader.inl"
#include <iostream>

int main()
{
    return reader(amount_to_read) ? 0 : 1;
}
