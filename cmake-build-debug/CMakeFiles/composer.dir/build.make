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
include CMakeFiles/composer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/composer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/composer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/composer.dir/flags.make

CMakeFiles/composer.dir/command/build/composer.cpp.o: CMakeFiles/composer.dir/flags.make
CMakeFiles/composer.dir/command/build/composer.cpp.o: /Projects/LEMP/command/build/composer.cpp
CMakeFiles/composer.dir/command/build/composer.cpp.o: CMakeFiles/composer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/composer.dir/command/build/composer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/composer.dir/command/build/composer.cpp.o -MF CMakeFiles/composer.dir/command/build/composer.cpp.o.d -o CMakeFiles/composer.dir/command/build/composer.cpp.o -c /Projects/LEMP/command/build/composer.cpp

CMakeFiles/composer.dir/command/build/composer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/composer.dir/command/build/composer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Projects/LEMP/command/build/composer.cpp > CMakeFiles/composer.dir/command/build/composer.cpp.i

CMakeFiles/composer.dir/command/build/composer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/composer.dir/command/build/composer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Projects/LEMP/command/build/composer.cpp -o CMakeFiles/composer.dir/command/build/composer.cpp.s

# Object files for target composer
composer_OBJECTS = \
"CMakeFiles/composer.dir/command/build/composer.cpp.o"

# External object files for target composer
composer_EXTERNAL_OBJECTS =

/Projects/LEMP/cbin/composer: CMakeFiles/composer.dir/command/build/composer.cpp.o
/Projects/LEMP/cbin/composer: CMakeFiles/composer.dir/build.make
/Projects/LEMP/cbin/composer: CMakeFiles/composer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Projects/LEMP/cbin/composer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/composer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/composer.dir/build: /Projects/LEMP/cbin/composer
.PHONY : CMakeFiles/composer.dir/build

CMakeFiles/composer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/composer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/composer.dir/clean

CMakeFiles/composer.dir/depend:
	cd /Projects/LEMP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Projects/LEMP /Projects/LEMP /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug/CMakeFiles/composer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/composer.dir/depend

