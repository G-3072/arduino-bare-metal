set(TARGET_NAME GPIO_TEST)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC
    src/gpio_time_test.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    inc
)

target_link_libraries(${TARGET_NAME}
    HAL.lib
)