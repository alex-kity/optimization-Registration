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
include libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/flags.make

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/flags.make
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o: libs/qCC_glWindow/QCC_GL_LIB_autogen/mocs_compilation.cpp
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o -MF CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o -c /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow/QCC_GL_LIB_autogen/mocs_compilation.cpp

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.i"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow/QCC_GL_LIB_autogen/mocs_compilation.cpp > CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.i

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.s"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow/QCC_GL_LIB_autogen/mocs_compilation.cpp -o CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.s

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/flags.make
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o: ../libs/qCC_glWindow/src/ccRenderingTools.cpp
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o -MF CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o.d -o CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o -c /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccRenderingTools.cpp

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.i"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccRenderingTools.cpp > CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.i

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.s"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccRenderingTools.cpp -o CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.s

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/flags.make
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o: ../libs/qCC_glWindow/src/ccGLWindow.cpp
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o -MF CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o.d -o CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o -c /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGLWindow.cpp

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.i"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGLWindow.cpp > CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.i

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.s"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGLWindow.cpp -o CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.s

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/flags.make
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o: ../libs/qCC_glWindow/src/ccGuiParameters.cpp
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o -MF CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o.d -o CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o -c /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGuiParameters.cpp

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.i"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGuiParameters.cpp > CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.i

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.s"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGuiParameters.cpp -o CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.s

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/flags.make
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o: ../libs/qCC_glWindow/src/ccGLUtils.cpp
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o -MF CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o.d -o CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o -c /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGLUtils.cpp

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.i"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGLUtils.cpp > CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.i

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.s"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && /usr/bin/x86_64-linux-gnu-g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow/src/ccGLUtils.cpp -o CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.s

# Object files for target QCC_GL_LIB
QCC_GL_LIB_OBJECTS = \
"CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o" \
"CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o" \
"CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o" \
"CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o"

# External object files for target QCC_GL_LIB
QCC_GL_LIB_EXTERNAL_OBJECTS =

libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/QCC_GL_LIB_autogen/mocs_compilation.cpp.o
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccRenderingTools.cpp.o
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLWindow.cpp.o
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGuiParameters.cpp.o
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/src/ccGLUtils.cpp.o
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/build.make
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_db/libQCC_DB_LIBd.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_db/extern/CCCoreLib/libCCCoreLibd.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libCGAL.so.11.0.1
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libgmp.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libgmpxx.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libmpfr.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libpthread.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libQt5Concurrent.so.5.5.1
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/CCFbo/libCC_FBO_LIBd.so
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.5.1
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.5.1
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGLExtensions.a
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.5.1
libs/qCC_glWindow/libQCC_GL_LIBd.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
libs/qCC_glWindow/libQCC_GL_LIBd.so: libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexkity/source/cc/CloudCompare-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libQCC_GL_LIBd.so"
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QCC_GL_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/build: libs/qCC_glWindow/libQCC_GL_LIBd.so
.PHONY : libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/build

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/clean:
	cd /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow && $(CMAKE_COMMAND) -P CMakeFiles/QCC_GL_LIB.dir/cmake_clean.cmake
.PHONY : libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/clean

libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/depend:
	cd /home/alexkity/source/cc/CloudCompare-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexkity/source/cc/CloudCompare-master /home/alexkity/source/cc/CloudCompare-master/libs/qCC_glWindow /home/alexkity/source/cc/CloudCompare-master/build /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow /home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/qCC_glWindow/CMakeFiles/QCC_GL_LIB.dir/depend

