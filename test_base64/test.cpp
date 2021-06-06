#include "pch.h"
#include <gtest/gtest.h>
#include "../base64.hpp"
#include <cstring>
#include <typeinfo>
#include <array>
TEST(base64, raw_array_sizeEqual)
{
    unsigned char origin[] = "string";
    auto encoded = sieve::base64::b64encode(origin);
    size_t size;
    auto decoded = sieve::base64::b64decode(encoded, &size);
    EXPECT_EQ(sizeof(origin), size);
    delete []decoded;
}

TEST(base64, raw_array_typeEqual)
{
    unsigned char origin[] = "string";
    auto size = sizeof(origin);
    auto encoded = sieve::base64::b64encode(origin);
    auto decoded = sieve::base64::b64decode(encoded);
    // it is array, so need to put the size into typeid
    EXPECT_EQ(typeid(origin[size]), typeid(decoded[size]));
    delete []decoded;
}

TEST(base64, raw_array_contentEqual)
{
    unsigned char origin[] = "string";
    auto encoded = sieve::base64::b64encode(origin);
    auto decoded = sieve::base64::b64decode(encoded);
    EXPECT_TRUE(0==std::memcmp(origin,decoded,sizeof(origin)));
    delete []decoded;
}

TEST(base64,std_array_contentEqual)
{
    std::array<unsigned char,7> origin{"string"};
    auto encoded = sieve::base64::b64encode(origin);
    auto decoded = sieve::base64::b64decode(encoded);
    EXPECT_TRUE(0==std::memcmp(origin.data(),decoded,origin.size()));
}
