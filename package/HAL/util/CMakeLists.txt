set(TARGET_NAME UTILITY.lib)

add_library(${TARGET_NAME} INTERFACE)

target_sources(${TARGET_NAME} INTERFACE
    
)

target_include_directories(${TARGET_NAME} INTERFACE
    inc
)

target_link_libraries(${TARGET_NAME} INTERFACE

)