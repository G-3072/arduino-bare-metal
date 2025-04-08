set(TARGET_NAME ADC.lib)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC
    src/adc.c
)

target_include_directories(${TARGET_NAME} PUBLIC

)

target_link_libraries(${TARGET_NAME} PUBLIC

)