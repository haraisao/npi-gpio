#
#
cmake_minimum_required(VERSION 3.0)
project(npi_giop)

find_package(Python3 COMPONENTS Interpreter Development)
include_directories(${Python3_INCLUDE_DIRS})

#
# Python module
add_library(npi_gpio SHARED src/gpio.c src/py_gpio.c)
target_link_libraries(npi_gpio ${Python3_LIBRARIES})
set_target_properties(npi_gpio PROPERTIES PREFIX "")


#
# Sample program
#add_executable(gpio_test src/gpio.c)
#target_compile_options(gpio_test PUBLIC -DMAIN_)

#
# Install....
