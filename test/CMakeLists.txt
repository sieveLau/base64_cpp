enable_testing()
find_package(GTest CONFIG REQUIRED)
add_executable(testbase64cpp test_main.cpp)
target_link_libraries(
  testbase64cpp
  PRIVATE
  GTest::gtest GTest::gtest_main
  base64
)
add_test(testbase64 testbase64cpp)