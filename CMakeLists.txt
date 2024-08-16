cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

project(Sparky)

add_subdirectory(lib)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

if(${CMAKE_BUILD_TARGET} MATCHES "Windows" AND ${CMAKE_BUILD_TYPE} MATCHES "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE inc)

target_link_libraries(${PROJECT_NAME} ethereal)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/shaders
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/assets
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)