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
include CMakeFiles/init-magento-env.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/init-magento-env.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/init-magento-env.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/init-magento-env.dir/flags.make

CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o: CMakeFiles/init-magento-env.dir/flags.make
CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o: /Projects/LEMP/command/build/init-magento-env.cpp
CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o: CMakeFiles/init-magento-env.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o -MF CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o.d -o CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o -c /Projects/LEMP/command/build/init-magento-env.cpp

CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Projects/LEMP/command/build/init-magento-env.cpp > CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.i

CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Projects/LEMP/command/build/init-magento-env.cpp -o CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.s

# Object files for target init-magento-env
init__magento__env_OBJECTS = \
"CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o"

# External object files for target init-magento-env
init__magento__env_EXTERNAL_OBJECTS =

/Projects/LEMP/cbin/init-magento-env: CMakeFiles/init-magento-env.dir/command/build/init-magento-env.cpp.o
/Projects/LEMP/cbin/init-magento-env: CMakeFiles/init-magento-env.dir/build.make
/Projects/LEMP/cbin/init-magento-env: CMakeFiles/init-magento-env.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Projects/LEMP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Projects/LEMP/cbin/init-magento-env"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/init-magento-env.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/init-magento-env.dir/build: /Projects/LEMP/cbin/init-magento-env
.PHONY : CMakeFiles/init-magento-env.dir/build

CMakeFiles/init-magento-env.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/init-magento-env.dir/cmake_clean.cmake
.PHONY : CMakeFiles/init-magento-env.dir/clean

CMakeFiles/init-magento-env.dir/depend:
	cd /Projects/LEMP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Projects/LEMP /Projects/LEMP /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug /Projects/LEMP/cmake-build-debug/CMakeFiles/init-magento-env.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/init-magento-env.dir/depend
