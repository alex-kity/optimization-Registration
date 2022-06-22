
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was CCCoreLibConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

####################################################################################

set(CCCoreLib_FOUND ON)
set_and_check(CCCoreLib_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")
set_and_check(CCCoreLib_LIBRARY_DIRS "${PACKAGE_PREFIX_DIR}/lib")
set(CCCoreLib_LIBRARIES "")

include(CMakeFindDependencyMacro)

if( ON )
  find_dependency( CGAL )
endif()
if( OFF )
  if( ${CMAKE_VERSION} VERSION_LESS "3.10.0" )
    find_package (TBB COMPONENTS tbb CONFIG )
  else()
    find_dependency( TBB COMPONENTS tbb CONFIG )
  endif()
endif()
if( ON )
  if( ${CMAKE_VERSION} VERSION_LESS "3.10.0" )
      find_package( Qt5 COMPONENTS Concurrent )
  else()
      find_dependency( Qt5 COMPONENTS Concurrent )
  endif()
endif()

include("${CMAKE_CURRENT_LIST_DIR}/CCCoreLibTargets.cmake")
