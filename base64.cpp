#include "base64.hpp"

auto sieve::base64::b64decode(const std::string &encoded, size_t *size) -> byte *
{
    const char* cstr = encoded.c_str();
    const auto arrsize = Base64decode_len(cstr);
    char* dest = new char[arrsize];
    Base64decode(dest,cstr);
    if(size!=nullptr) {
        *size=arrsize;
    }
    return reinterpret_cast<byte*>(dest);
}
