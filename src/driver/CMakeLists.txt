target_sources(${PROJECT_NAME} PRIVATE
    flash.c
    fpu.c
    init.c
    pwr.c
    rcc.c
    spi.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
)
