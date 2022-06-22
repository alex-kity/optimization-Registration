# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexkity/source/cc/CloudCompare-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexkity/source/cc/CloudCompare-master/build

# Include any dependencies generated for this target.
include libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/progress.make

# Include the compile flags for this target's objects.
include libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/flags.make

libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o: libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/flags.make
libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o: ../libs/CCPluginStub/src/ccDefaultPluginInterface.cpp
libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o: libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o -MF CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o.d -o CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o -c /home/alexkity/source/cc/CloudCompare-master/libs/CCPluginStub/src/ccDefaultPluginInterface.cpp

libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.i"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexkity/source/cc/CloudCompare-master/libs/CCPluginStub/src/ccDefaultPluginInterface.cpp > CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.i

libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.s"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexkity/source/cc/CloudCompare-master/libs/CCPluginStub/src/ccDefaultPluginInterface.cpp -o CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.s

# Object files for target CCPluginStub
CCPluginStub_OBJECTS = \
"CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o"

# External object files for target CCPluginStub
CCPluginStub_EXTERNAL_OBJECTS =

libs/CCPluginStub/libCCPluginStubd.a: libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/src/ccDefaultPluginInterface.cpp.o
libs/CCPluginStub/libCCPluginStubd.a: libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/build.make
libs/CCPluginStub/libCCPluginStubd.a: libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCCPluginStubd.a"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub && $(CMAKE_COMMAND) -P CMakeFiles/CCPluginStub.dir/cmake_clean_target.cmake
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CCPluginStub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/build: libs/CCPluginStub/libCCPluginStubd.a
.PHONY : libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/build

libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/clean:
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub && $(CMAKE_COMMAND) -P CMakeFiles/CCPluginStub.dir/cmake_clean.cmake
.PHONY : libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/clean

libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/depend:
	cd /home/alexkity/source/cc/CloudCompare-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexkity/source/cc/CloudCompare-master /home/alexkity/source/cc/CloudCompare-master/libs/CCPluginStub /home/alexkity/source/cc/CloudCompare-master/build /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/CCPluginStub/CMakeFiles/CCPluginStub.dir/depend

