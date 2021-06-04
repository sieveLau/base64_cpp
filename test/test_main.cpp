#include <gtest/gtest.h>
#include "../base64.hpp"
#include <cstring>
#include <typeinfo>
TEST(base64, sizeEqual)
{
    unsigned char origin[] = "string";
    auto encoded = sieve::base64::b64encode(origin);
    size_t size;
    auto decoded = sieve::base64::b64decode(encoded, &size);
    EXPECT_EQ(sizeof(origin), size);
    delete []decoded;
}

TEST(base64, typeEqual)
{
    unsigned char origin[] = "string";
    auto size = sizeof(origin);
    auto encoded = sieve::base64::b64encode(origin);
    auto decoded = sieve::base64::b64decode(encoded);
    // it is array, so need to put the size into typeid
    EXPECT_EQ(typeid(origin[size]), typeid(decoded[size]));
    delete []decoded;
}

TEST(base64, contentEqual)
{
    unsigned char origin[] = "string";
    auto encoded = sieve::base64::b64encode(origin);
    auto decoded = sieve::base64::b64decode(encoded);
    EXPECT_TRUE(0==std::memcmp(origin,decoded,sizeof(origin)));
    delete []decoded;
}
