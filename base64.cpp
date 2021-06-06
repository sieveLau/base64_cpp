#include "pch.h"
#include "base64.hpp"

auto sieve::base64::b64decode(const std::string &encoded, size_t *size) -> byte *
{
    const char* cstr = encoded.c_str();
    const auto arrsize = Base64decode_len(cstr);
    char* dest = new char[arrsize];

    // Base64decode_len创建了足够大的数组来容纳解码，但是真正的解码后大小要看Base64decode返回的值
    auto actual_size = Base64decode(dest,cstr);
    if(size!=nullptr) {
        *size=static_cast<size_t>(actual_size);
    }
    return reinterpret_cast<byte*>(dest);
}
