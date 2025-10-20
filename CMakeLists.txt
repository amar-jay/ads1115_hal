cmake_minimum_required(VERSION 3.13)
project(ads1115_hal LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Optionally allow a user to pass STM32 include/source dirs
if(NOT DEFINED STM32F4_HAL_INCLUDE_DIR)
  set(STM32F4_HAL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/stm32f4xx_hal_inc" CACHE PATH "Path to STM32F4 HAL headers (optional)")
endif()

if(NOT DEFINED STM32F4_HAL_SRC_DIR)
  set(STM32F4_HAL_SRC_DIR "${CMAKE_SOURCE_DIR}/stm32f4xx_hal_src" CACHE PATH "Path to STM32F4 HAL sources (optional)")
endif()

add_library(ads1115_hal STATIC
  src/ads1115_hal.c
)

target_include_directories(ads1115_hal PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${STM32F4_HAL_INCLUDE_DIR}>
)

# Provide a convenient target property so downstream projects know it's an stm32f4-like HAL
set_target_properties(ads1115_hal PROPERTIES
  VERSION 0.1.0
  SOVERSION 0
)

option(BUILD_EXAMPLE "Build example executable" ON)
if(BUILD_EXAMPLE)
  add_executable(example_adc examples/main.c)
  target_include_directories(example_adc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  target_link_libraries(example_adc PRIVATE ads1115_hal)
endif()

install(TARGETS ads1115_hal
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)
