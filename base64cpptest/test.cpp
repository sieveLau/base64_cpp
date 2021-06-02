#include "pch.h"

#include "../base64cpp/base64.hpp"

TEST(Base64, TestA) {
  unsigned char str[]="a string";
    auto encoded = sieve::base64::b64encode(str);
    auto decoded = sieve::base64::b64decode(encoded);
    EXPECT_TRUE(0 == std::memcmp(str,decoded,sizeof(str)));
    delete[] decoded;
}