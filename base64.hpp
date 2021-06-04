#pragma once

#include "c/base64.h"
#include <memory>
#include <string>


namespace sieve {
namespace base64 {
typedef unsigned char byte;

template<int N>
auto b64encode(byte (&bytes)[N]) -> std::string
{
    std::shared_ptr<char[]> base64_string(new char[Base64encode_len(N)]);
    //结尾包含'\0'
    Base64encode(base64_string.get(), reinterpret_cast<const char *>(bytes), N);
    return std::string(base64_string.get());
}

template<std::size_t SIZE>
auto b64encode(const std::array<byte, SIZE> &bytes) -> std::string
{
    std::shared_ptr<char[]> base64_string(new char[Base64encode_len(SIZE)]);
    //结尾包含'\0'
    Base64encode(base64_string.get(),
                 reinterpret_cast<const char *>(bytes),
                 SIZE);
    return std::string(base64_string.get());
}

auto b64decode(const std::string &encoded, size_t *size = nullptr) -> byte*;
} // namespace base64
} // namespace sieve
