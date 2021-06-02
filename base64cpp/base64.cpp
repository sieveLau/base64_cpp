#include "pch.h"
#include "base64.hpp"

auto sieve::base64::b64decode(const std::string &encoded_str, size_t *size) -> byte *
{
    auto decode_size = Base64decode_len(encoded_str.c_str());

    char * decoded = new char[decode_size];

    Base64decode(decoded,encoded_str.c_str());
    if(size!=nullptr)
    *size = decode_size;

    return reinterpret_cast<byte*>(decoded);
}
