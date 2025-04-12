set(TARGET_NAME INTERRUPTS.lib)

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} PRIVATE
    src/interrupt.c
    src/interrupt_base.c

)

target_include_directories(${TARGET_NAME} PUBLIC
    inc
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTILITY.lib
    GPIO.lib
)