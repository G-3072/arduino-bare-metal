set(TARGET_NAME INTERRUPTS.lib)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC
    src/interrupt.c
)

target_include_directories(${TARGET_NAME} PUBLIC

)

target_link_libraries(${TARGET_NAME} PUBLIC

)