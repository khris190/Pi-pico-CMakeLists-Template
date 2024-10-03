cmake_minimum_required(VERSION 3.12)

set(VERSION "0.0.1")
set(PROJECT_NAME "MyPicoProject")
# set board type, comment default is pico, can be pico_w, pico2
set(PICO_BOARD pico_w)
# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
project(${PROJECT_NAME} C CXX ASM)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(INCLUDE_DIR include)
set(PUBLIC_INCLUDE_DIRS ${INCLUDE_DIR})
set(PRIVATE_INCLUDE_DIRS ${INCLUDE_DIR})
set(LIBS
    ${LIBS}
    pico_stdlib
    pico_cyw43_arch_none
)
add_compile_definitions(VERSION="${VERSION}")
add_compile_definitions(PROJECT_NAME="${PROJECT_NAME}")
pico_sdk_init()

# include files
file(GLOB_RECURSE SOURCES ${INCLUDE_DIR}/*.c ${INCLUDE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${INCLUDE_DIR}/*.h ${INCLUDE_DIR}/*.hpp)

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME}
    main.c
    ${SOURCES}
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${PRIVATE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBS})
# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
