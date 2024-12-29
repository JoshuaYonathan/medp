cmake_minimum_required(VERSION 3.25)

project(
    app
    VERSION 0.1.0
    DESCRIPTION "Modern Embedded Development Platform"
    LANGUAGES C CXX ASM
)

add_executable(${CMAKE_PROJECT_NAME})

add_subdirectory(src)

set_target_properties(
    ${CMAKE_PROJECT_NAME}
    PROPERTIES
    SUFFIX .out
    LINK_DEPENDS ${CMAKE_SOURCE_DIR}/src/core/stm32f769.ld
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_BINARY_DIR}/output.map
            ${CMAKE_BINARY_DIR}/$<CONFIG>/output.map
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rm
            ${CMAKE_BINARY_DIR}/output.map
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY}
            -O ihex
            ${CMAKE_BINARY_DIR}/$<CONFIG>/${CMAKE_PROJECT_NAME}.out
            ${CMAKE_BINARY_DIR}/$<CONFIG>/${CMAKE_PROJECT_NAME}.hex
)
