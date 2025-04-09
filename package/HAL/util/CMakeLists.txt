set(TARGET_NAME UTILITY.lib)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC
    src/util.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    inc
)

target_link_libraries(${TARGET_NAME} PUBLIC

)