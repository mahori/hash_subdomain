project(hash_subdomain)

# C++

enable_language(CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Boost C++ Libraries

find_package(Boost COMPONENTS program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

# executable

set(HASH_SUBDOMAIN_SOURCES
  Hash.cpp
  MailAddress.cpp
  ProgramOptions.cpp
  Utils.cpp
  main.cpp
  )

add_executable(${PROJECT_NAME} ${HASH_SUBDOMAIN_SOURCES})

target_link_libraries(${PROJECT_NAME} Boost::program_options)
