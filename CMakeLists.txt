cmake_minimum_required(VERSION 3.12...3.22)

project(
    "Chess"
    LANGUAGES "C"
    VERSION "0.1.0"
    DESCRIPTION "Chess using CSFML/C"
    HOMEPAGE_URL "https://github.com/Phytolizer/Chess"
)

set(DEBUGGING OFF)

if(DEBUGGING)
    include(CMakePrintHelpers)
endif()

function(chess_executable TARGET_NAME)
    set(MULTI_VALUE_ARGS "SOURCES" "INCLUDE_DIRECTORIES" "LINK_LIBRARIES")
    cmake_parse_arguments(
        PARSE_ARGV 0 "CHESS_EXECUTABLE" "" "" "${MULTI_VALUE_ARGS}"
    )
    list(TRANSFORM "CHESS_EXECUTABLE_SOURCES" PREPEND "Source/${TARGET_NAME}/")
    add_executable("${TARGET_NAME}" "${CHESS_EXECUTABLE_SOURCES}")
    if(DEBUGGING)
        cmake_print_variables(
            "CHESS_EXECUTABLE_SOURCES" "CHESS_EXECUTABLE_INCLUDE_DIRECTORIES"
            "CHESS_EXECUTABLE_LINK_LIBRARIES"
        )
    endif()
    target_link_libraries(
        "${TARGET_NAME}" PRIVATE "${CHESS_EXECUTABLE_LINK_LIBRARIES}"
    )
    target_include_directories(
        "${TARGET_NAME}" PRIVATE "${CHESS_EXECUTABLE_INCLUDE_DIRECTORIES}"
    )
endfunction(chess_executable)

chess_executable(
    "Chess"
    SOURCES
    "Main.c"
    LINK_LIBRARIES
    "csfml-audio"
    "csfml-graphics"
    "csfml-system"
    "csfml-window"
)
