set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

find_program(CMAKE_C_COMPILER   arm-none-eabi-gcc REQUIRED)
find_program(CMAKE_CXX_COMPILER arm-none-eabi-g++ REQUIRED)
find_program(CMAKE_ASM_COMPILER arm-none-eabi-gcc REQUIRED)

find_program(CMAKE_AR       arm-none-eabi-gcc-ar REQUIRED)
find_program(CMAKE_NM       arm-none-eabi-gcc-nm REQUIRED)
find_program(CMAKE_OBJCOPY  arm-none-eabi-objcopy REQUIRED)
find_program(CMAKE_OBJDUMP  arm-none-eabi-objdump REQUIRED)
find_program(CMAKE_RANLIB   arm-none-eabi-gcc-ranlib REQUIRED)
find_program(CMAKE_SIZE     arm-none-eabi-size REQUIRED)
find_program(CMAKE_STRIP    arm-none-eabi-strip REQUIRED)

add_compile_options("$<$<COMPILE_LANGUAGE:C,CXX>:--specs=picolibc.specs>")
add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti;-fno-exceptions>")
add_compile_options("$<$<COMPILE_LANGUAGE:ASM>:-xassembler-with-cpp>")

add_compile_options(
    -march=armv7e-m
    -mfloat-abi=hard
    -mfpu=fpv5-d16
)

add_link_options(
    -march=armv7e-m
    -mfloat-abi=hard
    -mfpu=fpv5-d16
    --specs=picolibc.specs
)
