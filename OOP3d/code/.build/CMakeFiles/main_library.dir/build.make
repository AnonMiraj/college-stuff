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
CMAKE_SOURCE_DIR = /home/ezz/OOP3dr/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ezz/OOP3dr/code/.build

# Include any dependencies generated for this target.
include CMakeFiles/main_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_library.dir/flags.make

CMakeFiles/main_library.dir/src/carSys.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/carSys.cpp.o: /home/ezz/OOP3dr/code/src/carSys.cpp
CMakeFiles/main_library.dir/src/carSys.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_library.dir/src/carSys.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/carSys.cpp.o -MF CMakeFiles/main_library.dir/src/carSys.cpp.o.d -o CMakeFiles/main_library.dir/src/carSys.cpp.o -c /home/ezz/OOP3dr/code/src/carSys.cpp

CMakeFiles/main_library.dir/src/carSys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/carSys.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP3dr/code/src/carSys.cpp > CMakeFiles/main_library.dir/src/carSys.cpp.i

CMakeFiles/main_library.dir/src/carSys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/carSys.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP3dr/code/src/carSys.cpp -o CMakeFiles/main_library.dir/src/carSys.cpp.s

CMakeFiles/main_library.dir/src/car.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/car.cpp.o: /home/ezz/OOP3dr/code/src/car.cpp
CMakeFiles/main_library.dir/src/car.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_library.dir/src/car.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/car.cpp.o -MF CMakeFiles/main_library.dir/src/car.cpp.o.d -o CMakeFiles/main_library.dir/src/car.cpp.o -c /home/ezz/OOP3dr/code/src/car.cpp

CMakeFiles/main_library.dir/src/car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP3dr/code/src/car.cpp > CMakeFiles/main_library.dir/src/car.cpp.i

CMakeFiles/main_library.dir/src/car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP3dr/code/src/car.cpp -o CMakeFiles/main_library.dir/src/car.cpp.s

CMakeFiles/main_library.dir/src/customer.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/customer.cpp.o: /home/ezz/OOP3dr/code/src/customer.cpp
CMakeFiles/main_library.dir/src/customer.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_library.dir/src/customer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/customer.cpp.o -MF CMakeFiles/main_library.dir/src/customer.cpp.o.d -o CMakeFiles/main_library.dir/src/customer.cpp.o -c /home/ezz/OOP3dr/code/src/customer.cpp

CMakeFiles/main_library.dir/src/customer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/customer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP3dr/code/src/customer.cpp > CMakeFiles/main_library.dir/src/customer.cpp.i

CMakeFiles/main_library.dir/src/customer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/customer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP3dr/code/src/customer.cpp -o CMakeFiles/main_library.dir/src/customer.cpp.s

CMakeFiles/main_library.dir/src/invoice.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/invoice.cpp.o: /home/ezz/OOP3dr/code/src/invoice.cpp
CMakeFiles/main_library.dir/src/invoice.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main_library.dir/src/invoice.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/invoice.cpp.o -MF CMakeFiles/main_library.dir/src/invoice.cpp.o.d -o CMakeFiles/main_library.dir/src/invoice.cpp.o -c /home/ezz/OOP3dr/code/src/invoice.cpp

CMakeFiles/main_library.dir/src/invoice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/invoice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP3dr/code/src/invoice.cpp > CMakeFiles/main_library.dir/src/invoice.cpp.i

CMakeFiles/main_library.dir/src/invoice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/invoice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP3dr/code/src/invoice.cpp -o CMakeFiles/main_library.dir/src/invoice.cpp.s

CMakeFiles/main_library.dir/src/rentalagreement.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/rentalagreement.cpp.o: /home/ezz/OOP3dr/code/src/rentalagreement.cpp
CMakeFiles/main_library.dir/src/rentalagreement.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main_library.dir/src/rentalagreement.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/rentalagreement.cpp.o -MF CMakeFiles/main_library.dir/src/rentalagreement.cpp.o.d -o CMakeFiles/main_library.dir/src/rentalagreement.cpp.o -c /home/ezz/OOP3dr/code/src/rentalagreement.cpp

CMakeFiles/main_library.dir/src/rentalagreement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/rentalagreement.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP3dr/code/src/rentalagreement.cpp > CMakeFiles/main_library.dir/src/rentalagreement.cpp.i

CMakeFiles/main_library.dir/src/rentalagreement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/rentalagreement.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP3dr/code/src/rentalagreement.cpp -o CMakeFiles/main_library.dir/src/rentalagreement.cpp.s

CMakeFiles/main_library.dir/src/reservation.cpp.o: CMakeFiles/main_library.dir/flags.make
CMakeFiles/main_library.dir/src/reservation.cpp.o: /home/ezz/OOP3dr/code/src/reservation.cpp
CMakeFiles/main_library.dir/src/reservation.cpp.o: CMakeFiles/main_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main_library.dir/src/reservation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_library.dir/src/reservation.cpp.o -MF CMakeFiles/main_library.dir/src/reservation.cpp.o.d -o CMakeFiles/main_library.dir/src/reservation.cpp.o -c /home/ezz/OOP3dr/code/src/reservation.cpp

CMakeFiles/main_library.dir/src/reservation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_library.dir/src/reservation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ezz/OOP3dr/code/src/reservation.cpp > CMakeFiles/main_library.dir/src/reservation.cpp.i

CMakeFiles/main_library.dir/src/reservation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_library.dir/src/reservation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ezz/OOP3dr/code/src/reservation.cpp -o CMakeFiles/main_library.dir/src/reservation.cpp.s

# Object files for target main_library
main_library_OBJECTS = \
"CMakeFiles/main_library.dir/src/carSys.cpp.o" \
"CMakeFiles/main_library.dir/src/car.cpp.o" \
"CMakeFiles/main_library.dir/src/customer.cpp.o" \
"CMakeFiles/main_library.dir/src/invoice.cpp.o" \
"CMakeFiles/main_library.dir/src/rentalagreement.cpp.o" \
"CMakeFiles/main_library.dir/src/reservation.cpp.o"

# External object files for target main_library
main_library_EXTERNAL_OBJECTS =

libmain_library.a: CMakeFiles/main_library.dir/src/carSys.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/car.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/customer.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/invoice.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/rentalagreement.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/src/reservation.cpp.o
libmain_library.a: CMakeFiles/main_library.dir/build.make
libmain_library.a: CMakeFiles/main_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ezz/OOP3dr/code/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libmain_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/main_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_library.dir/build: libmain_library.a
.PHONY : CMakeFiles/main_library.dir/build

CMakeFiles/main_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_library.dir/clean

CMakeFiles/main_library.dir/depend:
	cd /home/ezz/OOP3dr/code/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ezz/OOP3dr/code /home/ezz/OOP3dr/code /home/ezz/OOP3dr/code/.build /home/ezz/OOP3dr/code/.build /home/ezz/OOP3dr/code/.build/CMakeFiles/main_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_library.dir/depend

