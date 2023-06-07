cmake_minimum_required(VERSION 3.5)

project(OOP2a)

############################################################
# Create a library    
############################################################

# Generate the library from the library sources
add_library(main_library  
  
    src/hrSystem.cpp
    src/department.cpp
    src/employee.cpp
    src/hourlyemployee.cpp
    src/commissionemployee.cpp
    src/salariedemployee.cpp
    src/manageremployee.cpp
    src/benefit.cpp
    src/dentalBenefit.cpp
    src/healthBenefit.cpp
 
#     src/contact.cpp
#     src/contacts.cpp
 )

target_include_directories(main_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
#
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
