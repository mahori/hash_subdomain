include(GoogleTest)

project(${PROJECT_NAME}-test)

set(GOOGLETEST_ROOT gtest/googletest CACHE STRING "Google Test source root")

include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest ${GOOGLETEST_SOURCES})

add_executable(${PROJECT_NAME}
    ../src/MailAddress.cpp
    MailAddressTest.cpp
    test.cpp
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
target_link_libraries(${PROJECT_NAME} gtest)

enable_testing()
gtest_add_tests(TARGET ${PROJECT_NAME})
add_test(mytest ${CMAKE_CURRENT_SOURCE_DIR}/test)
