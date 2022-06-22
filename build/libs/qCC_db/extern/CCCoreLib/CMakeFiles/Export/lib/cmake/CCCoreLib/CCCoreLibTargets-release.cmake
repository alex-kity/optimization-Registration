#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CCCoreLib::CCCoreLib" for configuration "Release"
set_property(TARGET CCCoreLib::CCCoreLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(CCCoreLib::CCCoreLib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libCCCoreLib.so"
  IMPORTED_SONAME_RELEASE "libCCCoreLib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS CCCoreLib::CCCoreLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_CCCoreLib::CCCoreLib "${_IMPORT_PREFIX}/lib/libCCCoreLib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
