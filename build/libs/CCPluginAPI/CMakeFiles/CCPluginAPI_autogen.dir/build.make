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

# Utility rule file for CCPluginAPI_autogen.

# Include any custom commands dependencies for this target.
include libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/progress.make

libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target CCPluginAPI"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI && /usr/local/bin/cmake -E cmake_autogen /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/AutogenInfo.json Debug

CCPluginAPI_autogen: libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen
CCPluginAPI_autogen: libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/build.make
.PHONY : CCPluginAPI_autogen

# Rule to build all files generated by this target.
libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/build: CCPluginAPI_autogen
.PHONY : libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/build

libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/clean:
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI && $(CMAKE_COMMAND) -P CMakeFiles/CCPluginAPI_autogen.dir/cmake_clean.cmake
.PHONY : libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/clean

libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/depend:
	cd /home/alexkity/source/cc/CloudCompare-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexkity/source/cc/CloudCompare-master /home/alexkity/source/cc/CloudCompare-master/libs/CCPluginAPI /home/alexkity/source/cc/CloudCompare-master/build /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI /home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/CCPluginAPI/CMakeFiles/CCPluginAPI_autogen.dir/depend

