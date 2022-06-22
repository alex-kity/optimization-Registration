# Install script for directory: /home/alexkity/source/cc/CloudCompare-master/qCC/translations

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cloudcompare/translations" TYPE FILE FILES
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_de.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_es_AR.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_fr.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_ja.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_kr.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_pt.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_ru.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/CloudCompare_zh.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/qt_de.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/qt_fr.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/qt_ja.qm"
    "/home/alexkity/source/cc/CloudCompare-master/build/qCC/translations/qt_ru.qm"
    )
endif()

