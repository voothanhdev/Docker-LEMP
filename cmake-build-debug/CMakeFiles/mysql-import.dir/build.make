# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Projects/LEMP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Projects/LEMP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mysql-import.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mysql-import.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mysql-import.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mysql-import.dir/flags.make

CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o: CMakeFiles/mysql-import.dir/flags.make
CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o: /Projects/LEMP/command/build/mysql-import.cpp
CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o: CMakeFiles/mysql-import.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o -MF CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o.d -o CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o -c /Projects/LEMP/command/build/mysql-import.cpp

CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Projects/LEMP/command/build/mysql-import.cpp > CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.i

CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Projects/LEMP/command/build/mysql-import.cpp -o CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.s

# Object files for target mysql-import
mysql__import_OBJECTS = \
"CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o"

# External object files for target mysql-import
mysql__import_EXTERNAL_OBJECTS =

/Projects/LEMP/cbin/mysql-import: CMakeFiles/mysql-import.dir/command/build/mysql-import.cpp.o
/Projects/LEMP/cbin/mysql-import: CMakeFiles/mysql-import.dir/build.make
/Projects/LEMP/cbin/mysql-import: CMakeFiles/mysql-import.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Projects/LEMP/cbin/mysql-import"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysql-import.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mysql-import.dir/build: /Projects/LEMP/cbin/mysql-import
.PHONY : CMakeFiles/mysql-import.dir/build

CMakeFiles/mysql-import.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mysql-import.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mysql-import.dir/clean

CMakeFiles/mysql-import.dir/depend:
	cd /Projects/LEMP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Projects/LEMP /Projects/LEMP /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug/CMakeFiles/mysql-import.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mysql-import.dir/depend

