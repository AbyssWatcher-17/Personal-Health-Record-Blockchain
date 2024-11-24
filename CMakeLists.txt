cmake_minimum_required(VERSION 3.10)
project(Personal-Health-Record-Blockchain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a list of all source files
set(SOURCES
    main.cpp
    Base/Block.cpp
    Base/BlockChain.cpp
    Base/Record.cpp
    Users/Doctor.cpp
    Users/Patient.cpp
)


# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Base
    ${CMAKE_CURRENT_SOURCE_DIR}/Users
)