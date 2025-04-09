set(TARGET_NAME HAL.lib)

add_subdirectory(ADC)
add_subdirectory(GPIO)
add_subdirectory(interrupts)
add_subdirectory(timers)
add_subdirectory(USART)
add_subdirectory(util)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC

)

target_include_directories(${TARGET_NAME} PUBLIC

)

target_link_libraries(${TARGET_NAME} PUBLIC
    ADC.lib
    GPIO.lib
    INTERRUPTS.lib
    TIMERS.lib
    USART.lib
)

