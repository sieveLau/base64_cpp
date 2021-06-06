#include "pch.h"
#include "base64.hpp"

auto sieve::base64::b64decode(const std::string &encoded, size_t *size) -> byte *
{
    const char* cstr = encoded.c_str();
    const auto arrsize = Base64decode_len(cstr);
    char* dest = new char[arrsize];

    // Base64decode_len�������㹻������������ɽ��룬���������Ľ�����СҪ��Base64decode���ص�ֵ
    auto actual_size = Base64decode(dest,cstr);
    if(size!=nullptr) {
        *size=static_cast<size_t>(actual_size);
    }
    return reinterpret_cast<byte*>(dest);
}
