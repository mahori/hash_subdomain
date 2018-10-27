project(hash_subdomain_test)

# C++

enable_language(CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DMAHORI_TEST)

# Google Test

include(GoogleTest)

set(GOOGLE_TEST_ROOT googletest/googletest)
set(GOOGLE_MOCK_ROOT googletest/googlemock)
set(GOOGLE_TEST_SOURCES
  ${PROJECT_SOURCE_DIR}/${GOOGLE_TEST_ROOT}/src/gtest-all.cc
  ${PROJECT_SOURCE_DIR}/${GOOGLE_TEST_ROOT}/src/gtest_main.cc
  ${PROJECT_SOURCE_DIR}/${GOOGLE_MOCK_ROOT}/src/gmock-all.cc
  )

include_directories(
  ${PROJECT_SOURCE_DIR}/${GOOGLE_TEST_ROOT}
  ${PROJECT_SOURCE_DIR}/${GOOGLE_TEST_ROOT}/include
  ${PROJECT_SOURCE_DIR}/${GOOGLE_MOCK_ROOT}
  ${PROJECT_SOURCE_DIR}/${GOOGLE_MOCK_ROOT}/include
  )

add_library(googletest ${GOOGLE_TEST_SOURCES})

# Boost C++ Libraries

find_package(Boost COMPONENTS program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

# executable

set(HASH_SUBDOMAIN_TEST_SOURCES
  ../src/Hash.cpp
  ../src/MailAddress.cpp
  ../src/ProgramOptions.cpp
  ../src/Utils.cpp
  HashTest.cpp
  MailAddressTest.cpp
  ProgramOptionsTest.cpp
  SubdomainTest.cpp
  )

add_executable(${PROJECT_NAME} ${HASH_SUBDOMAIN_TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} Boost::program_options)
target_link_libraries(${PROJECT_NAME} googletest)

# test

enable_testing()

gtest_discover_tests(${PROJECT_NAME})
add_test(mytest ${CMAKE_CURRENT_SOURCE_DIR}/test)
