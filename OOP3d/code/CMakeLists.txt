cmake_minimum_required(VERSION 3.5)

project(OOP3d)

############################################################
# Create a library    
############################################################

# Generate the library from the library sources
add_library(main_library  
  src/carSys.cpp
  src/car.cpp
  src/customer.cpp
  src/invoice.cpp
  src/rentalagreement.cpp
  src/reservation.cpp
  
)

target_include_directories(main_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(main 
    main.cpp
)

# link the new main_library target with the main target
target_link_libraries( main
    PRIVATE 
        main_library
)
