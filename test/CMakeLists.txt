project(Unittest CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

file(GLOB_RECURSE SOURCE
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Now simply link against gtest or gtest_main as needed. Eg
include(GoogleTest)
add_definitions(-DTEST)
set(CMAKE_CXX_FLAGS   "-g")
add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} gtest_main gtest gmock)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})