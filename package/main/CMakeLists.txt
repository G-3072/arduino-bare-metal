set(TARGET_NAME arduino-bare-metal)

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PRIVATE
    src/main.c
    # src/atmega328p_startup.S
)

target_link_libraries(${TARGET_NAME} PRIVATE
    HAL.lib
)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND avr-objcopy -O ihex $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.hex
    COMMENT "Generating HEX file"
)
