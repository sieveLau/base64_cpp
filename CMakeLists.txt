cmake_minimum_required(VERSION 3.16)

if(TARGET base64)
  return()
endif(TARGET base64)



project(base64cpp)
set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)


add_subdirectory(c)
add_library(base64 STATIC base64.cpp base64.hpp)
target_link_libraries(base64 base64c)

# add googletest https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)