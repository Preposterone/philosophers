cmake_minimum_required(VERSION 3.19)
project(philosophers)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "-DDARWIN")

include_directories(philo/inc)

#libft target
add_subdirectory(philo/libft)

file(GLOB PHILO_SRCS philo/src/*.c)
list(FILTER PHILO_SRCS EXCLUDE REGEX ".*main.c$")


#philosophers
add_executable(philosophers ${PHILO_SRCS} philo/src/main.c)
target_link_libraries(philosophers libft pthread)


#test prereq
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(googletest)

#tests
add_executable(test_args philo/tests/test_parse_args.cpp ${PHILO_SRCS})
target_link_libraries(test_args gtest_main libft pthread)
