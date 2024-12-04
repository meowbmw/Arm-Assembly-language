cmake_minimum_required(VERSION 3.14)

# 设置编译器
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)

# 设置生成目标架构
set(CMAKE_SYSTEM_PROCESSOR aarch64)

project(ARM64)

# 添加GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_language(ASM)

# 添加测试
add_executable(hello_test hello_test.cc hello.s)
enable_testing()

target_link_libraries(hello_test gtest gtest_main)

# 使用QEMU运行测试
add_test(
    NAME hello_test
    COMMAND "qemu-aarch64" -L /usr/aarch64-linux-gnu hello_test
)

# cmake -S . -B build && cmake --build build
# cmake -S . -B build && cmake --build build && cd ./build && ctest && cd .. 