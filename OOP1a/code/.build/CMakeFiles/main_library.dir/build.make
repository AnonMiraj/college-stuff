# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ezz/OOP1a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ezz/OOP1a/.build

# Include any dependencies generated for this target.
include CMakeFiles/main_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_library.dir/flags.make

CMakeFiles/main_library.dir/src/phone.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/phone.cpp.o: /home/ezz/OOP1a/src/phone.cpp
CMakeFiles/main_library.dir/src/phone.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP1a/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_library.dir/src/phone.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/phone.cpp.o -MF CMakeFiles/main_library.dir/src/phone.cpp.o.d -o CMakeFiles/main_library.dir/src/phone.cpp.o -c /home/ezz/OOP1a/src/phone.cpp

CMakeFiles/main_library.dir/src/phone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/phone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP1a/src/phone.cpp > CMakeFiles/main_library.dir/src/phone.cpp.i

CMakeFiles/main_library.dir/src/phone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/phone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP1a/src/phone.cpp -o CMakeFiles/main_library.dir/src/phone.cpp.s

CMakeFiles/main_library.dir/src/address.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/address.cpp.o: /home/ezz/OOP1a/src/address.cpp
CMakeFiles/main_library.dir/src/address.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP1a/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_library.dir/src/address.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/address.cpp.o -MF CMakeFiles/main_library.dir/src/address.cpp.o.d -o CMakeFiles/main_library.dir/src/address.cpp.o -c /home/ezz/OOP1a/src/address.cpp

CMakeFiles/main_library.dir/src/address.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/address.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP1a/src/address.cpp > CMakeFiles/main_library.dir/src/address.cpp.i

CMakeFiles/main_library.dir/src/address.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/address.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP1a/src/address.cpp -o CMakeFiles/main_library.dir/src/address.cpp.s

CMakeFiles/main_library.dir/src/email.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/email.cpp.o: /home/ezz/OOP1a/src/email.cpp
CMakeFiles/main_library.dir/src/email.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP1a/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_library.dir/src/email.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/email.cpp.o -MF CMakeFiles/main_library.dir/src/email.cpp.o.d -o CMakeFiles/main_library.dir/src/email.cpp.o -c /home/ezz/OOP1a/src/email.cpp

CMakeFiles/main_library.dir/src/email.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/email.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP1a/src/email.cpp > CMakeFiles/main_library.dir/src/email.cpp.i

CMakeFiles/main_library.dir/src/email.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/email.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP1a/src/email.cpp -o CMakeFiles/main_library.dir/src/email.cpp.s

CMakeFiles/main_library.dir/src/contact.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/contact.cpp.o: /home/ezz/OOP1a/src/contact.cpp
CMakeFiles/main_library.dir/src/contact.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP1a/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main_library.dir/src/contact.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/contact.cpp.o -MF CMakeFiles/main_library.dir/src/contact.cpp.o.d -o CMakeFiles/main_library.dir/src/contact.cpp.o -c /home/ezz/OOP1a/src/contact.cpp

CMakeFiles/main_library.dir/src/contact.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/contact.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP1a/src/contact.cpp > CMakeFiles/main_library.dir/src/contact.cpp.i

CMakeFiles/main_library.dir/src/contact.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/contact.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP1a/src/contact.cpp -o CMakeFiles/main_library.dir/src/contact.cpp.s

CMakeFiles/main_library.dir/src/contacts.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/contacts.cpp.o: /home/ezz/OOP1a/src/contacts.cpp
CMakeFiles/main_library.dir/src/contacts.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP1a/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main_library.dir/src/contacts.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/contacts.cpp.o -MF CMakeFiles/main_library.dir/src/contacts.cpp.o.d -o CMakeFiles/main_library.dir/src/contacts.cpp.o -c /home/ezz/OOP1a/src/contacts.cpp

CMakeFiles/main_library.dir/src/contacts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/contacts.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP1a/src/contacts.cpp > CMakeFiles/main_library.dir/src/contacts.cpp.i

CMakeFiles/main_library.dir/src/contacts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/contacts.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP1a/src/contacts.cpp -o CMakeFiles/main_library.dir/src/contacts.cpp.s

# Object files for target main_library
main_library_OBJECTS = \
"CMakeFiles/main_library.dir/src/phone.cpp.o" \
"CMakeFiles/main_library.dir/src/address.cpp.o" \
"CMakeFiles/main_library.dir/src/email.cpp.o" \
"CMakeFiles/main_library.dir/src/contact.cpp.o" \
"CMakeFiles/main_library.dir/src/contacts.cpp.o"

# External object files for target main_library
main_library_EXTERNAL_OBJECTS =

libmain_library.a: CMakeFiles/main_library.dir/src/phone.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/address.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/email.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/contact.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/contacts.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/build.make
libmain_library.a: CMakeFiles/main_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ezz/OOP1a/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libmain_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/main_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_library.dir/build: libmain_library.a
.PHONY : CMakeFiles/main_library.dir/build

CMakeFiles/main_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_library.dir/clean

CMakeFiles/main_library.dir/depend:
	cd /home/ezz/OOP1a/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ezz/OOP1a /home/ezz/OOP1a /home/ezz/OOP1a/.build /home/ezz/OOP1a/.build /home/ezz/OOP1a/.build/CMakeFiles/main_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_library.dir/depend

