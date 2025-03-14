#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "controller_interface::controller_interface" for configuration ""
set_property(TARGET controller_interface::controller_interface APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(controller_interface::controller_interface PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcontroller_interface.so"
  IMPORTED_SONAME_NOCONFIG "libcontroller_interface.so"
  )

list(APPEND _cmake_import_check_targets controller_interface::controller_interface )
list(APPEND _cmake_import_check_files_for_controller_interface::controller_interface "${_IMPORT_PREFIX}/lib/libcontroller_interface.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
