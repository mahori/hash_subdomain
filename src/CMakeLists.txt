find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    MailAddress.cpp
    ProgramOptions.cpp
    Subdomain.cpp
    main.cpp
    )

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
