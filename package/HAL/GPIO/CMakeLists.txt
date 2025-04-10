set(TARGET_NAME GPIO.lib)

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} PRIVATE
    src/gpio.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    inc
)

target_link_libraries(${TARGET_NAME} PUBLIC

)