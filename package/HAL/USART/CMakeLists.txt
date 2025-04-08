set(TARGET_NAME USART.lib)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC
    src/usart.c
)

target_include_directories(${TARGET_NAME} PUBLIC

)

target_link_libraries(${TARGET_NAME} PUBLIC

)