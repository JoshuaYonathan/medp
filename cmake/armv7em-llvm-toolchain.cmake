set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_C_COMPILER_TARGET   thumbv7m-unknown-none-eabihf CACHE STRING "Target Triple" FORCE)
set(CMAKE_CXX_COMPILER_TARGET thumbv7m-unknown-none-eabihf CACHE STRING "Target Triple" FORCE)
set(CMAKE_ASM_COMPILER_TARGET thumbv7m-unknown-none-eabihf CACHE STRING "Target Triple" FORCE)

find_program(CMAKE_C_COMPILER   clang REQUIRED)
find_program(CMAKE_CXX_COMPILER clang++ REQUIRED)
find_program(CMAKE_ASM_COMPILER clang REQUIRED)

find_program(CMAKE_AR       llvm-ar REQUIRED)
find_program(CMAKE_NM       llvm-nm REQUIRED)
find_program(CMAKE_OBJCOPY  llvm-objcopy REQUIRED)
find_program(CMAKE_OBJDUMP  llvm-objdump REQUIRED)
find_program(CMAKE_RANLIB   llvm-ranlib REQUIRED)
find_program(CMAKE_SIZE     llvm-size REQUIRED)
find_program(CMAKE_STRIP    llvm-strip REQUIRED)

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
)
