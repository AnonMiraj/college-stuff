cmake_minimum_required(VERSION 3.5)

project(contacts)

############################################################
# Create a library
############################################################

#Generate the library from the library sources
add_library(main_library  
    src/phone.cpp
    src/address.cpp
    src/email.cpp
    src/contact.cpp
    src/contacts.cpp
)

target_include_directories(main_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(main 
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( main
    PRIVATE 
        main_library
)
