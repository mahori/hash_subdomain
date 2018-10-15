project(${PROJECT_NAME}_test)

# library

include(GoogleTest)

set(GOOGLETEST_ROOT gtest/googletest CACHE STRING "Google Test source root")
set(GOOGLEMOCK_ROOT gtest/googlemock CACHE STRING "Google Mock source root")

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/src/gmock-all.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(gtest ${GOOGLETEST_SOURCES})

# executable

find_package(Boost COMPONENTS program_options REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(
    SYSTEM
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/include
    ${Boost_INCLUDE_DIRS}
    )

add_executable(${PROJECT_NAME}
    ../src/Hash.cpp
    ../src/MailAddress.cpp
    ../src/ProgramOptions.cpp
    ../src/Utils.cpp
    HashTest.cpp
    MailAddressTest.cpp
    ProgramOptionsTest.cpp
    SubdomainTest.cpp
    )

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} gtest)

# test

enable_testing()

gtest_discover_tests(${PROJECT_NAME})
add_test(mytest ${CMAKE_CURRENT_SOURCE_DIR}/test)
