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
include CMakeFiles/magento.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/magento.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/magento.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/magento.dir/flags.make

CMakeFiles/magento.dir/command/build/magento.cpp.o: CMakeFiles/magento.dir/flags.make
CMakeFiles/magento.dir/command/build/magento.cpp.o: /Projects/LEMP/command/build/magento.cpp
CMakeFiles/magento.dir/command/build/magento.cpp.o: CMakeFiles/magento.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/magento.dir/command/build/magento.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/magento.dir/command/build/magento.cpp.o -MF CMakeFiles/magento.dir/command/build/magento.cpp.o.d -o CMakeFiles/magento.dir/command/build/magento.cpp.o -c /Projects/LEMP/command/build/magento.cpp

CMakeFiles/magento.dir/command/build/magento.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/magento.dir/command/build/magento.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Projects/LEMP/command/build/magento.cpp > CMakeFiles/magento.dir/command/build/magento.cpp.i

CMakeFiles/magento.dir/command/build/magento.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/magento.dir/command/build/magento.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Projects/LEMP/command/build/magento.cpp -o CMakeFiles/magento.dir/command/build/magento.cpp.s

# Object files for target magento
magento_OBJECTS = \
"CMakeFiles/magento.dir/command/build/magento.cpp.o"

# External object files for target magento
magento_EXTERNAL_OBJECTS =

/Projects/LEMP/cbin/magento: CMakeFiles/magento.dir/command/build/magento.cpp.o
/Projects/LEMP/cbin/magento: CMakeFiles/magento.dir/build.make
/Projects/LEMP/cbin/magento: CMakeFiles/magento.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Projects/LEMP/cbin/magento"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/magento.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/magento.dir/build: /Projects/LEMP/cbin/magento
.PHONY : CMakeFiles/magento.dir/build

CMakeFiles/magento.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/magento.dir/cmake_clean.cmake
.PHONY : CMakeFiles/magento.dir/clean

CMakeFiles/magento.dir/depend:
	cd /Projects/LEMP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Projects/LEMP /Projects/LEMP /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug/CMakeFiles/magento.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/magento.dir/depend
