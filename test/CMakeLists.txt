include(GoogleTest)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

project(${PROJECT_NAME}-test)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

enable_testing()
add_test(mytest ${CMAKE_CURRENT_SOURCE_DIR}/test)
gtest_add_tests(TARGET ${PROJECT_NAME})
