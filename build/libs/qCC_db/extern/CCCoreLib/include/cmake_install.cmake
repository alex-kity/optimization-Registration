# Install script for directory: /home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CCCoreLib" TYPE FILE FILES
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/AutoSegmentationTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/BoundingBox.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCConst.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCCoreLib.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCGeom.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCMiscTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCPlatform.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCShareable.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCToolbox.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CCTypes.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ChamferDistanceTransform.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/CloudSamplingTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ConjugateGradient.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/Delaunay2dMesh.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/DgmOctree.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/DgmOctreeReferenceCloud.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/DistanceComputationTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ErrorFunction.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/FastMarching.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/FastMarchingForPropagation.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/Garbage.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericCloud.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericDistribution.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericIndexedCloud.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericIndexedCloudPersist.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericIndexedMesh.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericMesh.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericOctree.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericProgressCallback.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GenericTriangle.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/GeometricalAnalysisTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/Grid3D.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/Jacobi.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/KdTree.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/LocalModel.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ManualSegmentationTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/MathTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/MeshSamplingTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/Neighbourhood.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/NormalDistribution.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ParallelSort.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/PointCloud.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/PointCloudTpl.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/PointProjectionTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/Polyline.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/RayAndBox.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ReferenceCloud.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/RegistrationTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/SaitoSquaredDistanceTransform.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ScalarField.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/ScalarFieldTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/SimpleMesh.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/SimpleTriangle.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/SquareMatrix.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/StatisticalTestingTools.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/TrueKdTree.h"
    "/home/alexkity/source/cc/CloudCompare-master/libs/qCC_db/extern/CCCoreLib/include/WeibullDistribution.h"
    )
endif()

