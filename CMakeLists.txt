cmake_minimum_required(VERSION 3.20)

project(Lab_OOP4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_library(lab_oop4_lib INTERFACE)
target_include_directories(lab_oop4_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(Lab_OOP4
    main.cpp
)

target_link_libraries(Lab_OOP4 PRIVATE
    lab_oop4_lib
)

include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(Lab_OOP4_tests
    tests/tests.cpp
)

target_link_libraries(Lab_OOP4_tests PRIVATE
    lab_oop4_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Lab_OOP4_tests)
