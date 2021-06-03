enable_testing()
#find_package(GTest CONFIG REQUIRED)
add_executable(testbase64cpp test_main.cpp)
target_link_libraries(
  testbase64cpp
  PRIVATE
  gtest_main
  base64
)
include(GoogleTest)
gtest_discover_tests(testbase64cpp)