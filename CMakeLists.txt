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

function(chess_library TARGET_NAME)
    set(MULTI_VALUE_ARGS "SOURCES" "INCLUDE_DIRECTORIES" "LINK_LIBRARIES")
    cmake_parse_arguments(
        PARSE_ARGV 0 "CHESS_LIBRARY" "" "" "${MULTI_VALUE_ARGS}"
    )
    list(TRANSFORM "CHESS_LIBRARY_SOURCES" PREPEND "Source/${TARGET_NAME}/")
    add_library("${TARGET_NAME}" STATIC "${CHESS_LIBRARY_SOURCES}")
    if(DEBUGGING)
        cmake_print_variables(
            "CHESS_LIBRARY_SOURCES" "CHESS_LIBRARY_INCLUDE_DIRECTORIES"
            "CHESS_LIBRARY_LINK_LIBRARIES"
        )
    endif()
    target_link_libraries(
        "${TARGET_NAME}" PUBLIC "${CHESS_LIBRARY_LINK_LIBRARIES}"
    )
    target_include_directories(
        "${TARGET_NAME}" PUBLIC "${CHESS_LIBRARY_INCLUDE_DIRECTORIES}"
    )
endfunction(chess_library)

chess_library(
    "ChessLib"
    SOURCES
    "ChessGrid.c"
    "ChessPieceType.c"
    INCLUDE_DIRECTORIES
    "Include"
    LINK_LIBRARIES
    "csfml-graphics"
    "csfml-system"
    "csfml-window"
)

chess_executable("Chess" SOURCES "Main.c" LINK_LIBRARIES "ChessLib")
