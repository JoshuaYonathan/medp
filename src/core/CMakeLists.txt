target_sources(${PROJECT_NAME} PRIVATE
    startup_stm32f769.c
    syscalls.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
)
