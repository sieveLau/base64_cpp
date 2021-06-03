#include <gtest/gtest.h>
#include "../base64.hpp"
#include <cstring>
TEST(base64,contentequal)
{
    unsigned char origin[]="string";
    auto encoded = sieve::base64::b64encode(origin);
    auto decoded = sieve::base64::b64decode(encoded);
    EXPECT_TRUE(0==std::memcmp(origin,decoded,sizeof(origin)));
}