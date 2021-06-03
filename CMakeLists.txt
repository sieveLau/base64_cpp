add_subdirectory(c)
add_library(base64 STATIC base64.cpp base64.hpp)
target_link_libraries(base64 base64c)

add_subdirectory(test)