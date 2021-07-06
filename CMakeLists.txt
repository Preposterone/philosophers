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
