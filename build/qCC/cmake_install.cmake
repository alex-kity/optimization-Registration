# Install script for directory: /home/alexkity/source/cc/CloudCompare-master/qCC

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/x86_64-linux-gnu-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper"
         RPATH "/usr/local/lib/cloudcompare")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/alexkity/source/cc/CloudCompare-master/build/qCC/PointCloudSuper")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper"
         OLD_RPATH "/usr/local/boost/lib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCAppCommon:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_io:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db/extern/CCCoreLib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCFbo:"
         NEW_RPATH "/usr/local/lib/cloudcompare")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PointCloudSuper")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare" TYPE FILE FILES "/CHANGELOG.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare" TYPE FILE FILES "/home/alexkity/source/cc/CloudCompare-master/qCC/bin_other/license.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare" TYPE FILE FILES "/home/alexkity/source/cc/CloudCompare-master/qCC/bin_other/global_shift_list_template.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare/shaders/Bilateral" TYPE FILE FILES "/home/alexkity/source/cc/CloudCompare-master/libs/CCFbo/shaders/Bilateral/bilateral.frag")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare/shaders/Bilateral" TYPE FILE FILES "/home/alexkity/source/cc/CloudCompare-master/libs/CCFbo/shaders/Bilateral/bilateral.vert")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare/shaders/ColorRamp" TYPE FILE FILES "/home/alexkity/source/cc/CloudCompare-master/qCC/shaders/ColorRamp/color_ramp.frag")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so"
         RPATH "/usr/local/lib/cloudcompare")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins" TYPE SHARED_LIBRARY FILES "/home/alexkity/source/cc/CloudCompare-master/build/plugins/core/IO/qCoreIO/libQCORE_IO_PLUGINd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so"
         OLD_RPATH "/home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_io:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db/extern/CCCoreLib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCFbo:"
         NEW_RPATH "/usr/local/lib/cloudcompare")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQCORE_IO_PLUGINd.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so"
         RPATH "/usr/local/lib/cloudcompare")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins" TYPE SHARED_LIBRARY FILES "/home/alexkity/source/cc/CloudCompare-master/build/plugins/core/Standard/qBroom/libQBROOM_PLUGINd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so"
         OLD_RPATH "/home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_io:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db/extern/CCCoreLib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCFbo:"
         NEW_RPATH "/usr/local/lib/cloudcompare")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQBROOM_PLUGINd.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so"
         RPATH "/usr/local/lib/cloudcompare")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins" TYPE SHARED_LIBRARY FILES "/home/alexkity/source/cc/CloudCompare-master/build/plugins/core/Standard/qPCL/libQPCL_PLUGINd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so"
         OLD_RPATH "/home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_io:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db/extern/CCCoreLib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCFbo:"
         NEW_RPATH "/usr/local/lib/cloudcompare")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_PLUGINd.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so"
         RPATH "/usr/local/lib/cloudcompare")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins" TYPE SHARED_LIBRARY FILES "/home/alexkity/source/cc/CloudCompare-master/build/plugins/core/Standard/qPCL/PclIO/libQPCL_IO_PLUGINd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so"
         OLD_RPATH "/home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_io:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db/extern/CCCoreLib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCFbo:"
         NEW_RPATH "/usr/local/lib/cloudcompare")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQPCL_IO_PLUGINd.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so"
         RPATH "/usr/local/lib/cloudcompare")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins" TYPE SHARED_LIBRARY FILES "/home/alexkity/source/cc/CloudCompare-master/build/plugins/core/Standard/qRANSAC_SD/libQRANSAC_SD_PLUGINd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so"
         OLD_RPATH "/home/alexkity/source/cc/CloudCompare-master/build/libs/CCPluginAPI:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_glWindow:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_io:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db:/home/alexkity/source/cc/CloudCompare-master/build/libs/qCC_db/extern/CCCoreLib:/home/alexkity/source/cc/CloudCompare-master/build/libs/CCFbo:"
         NEW_RPATH "/usr/local/lib/cloudcompare")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/x86_64-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cloudcompare/plugins/libQRANSAC_SD_PLUGINd.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimex" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/alexkity/source/cc/CloudCompare-master/build/qCC/db_tree/cmake_install.cmake")
  include("/home/alexkity/source/cc/CloudCompare-master/build/qCC/pluginManager/cmake_install.cmake")
  include("/home/alexkity/source/cc/CloudCompare-master/build/qCC/slam/cmake_install.cmake")
  include("/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/cmake_install.cmake")

endif()

