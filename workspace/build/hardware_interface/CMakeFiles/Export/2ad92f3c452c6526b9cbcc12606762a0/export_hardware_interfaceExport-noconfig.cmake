#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hardware_interface::mock_components" for configuration ""
set_property(TARGET hardware_interface::mock_components APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(hardware_interface::mock_components PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmock_components.so"
  IMPORTED_SONAME_NOCONFIG "libmock_components.so"
  )

list(APPEND _cmake_import_check_targets hardware_interface::mock_components )
list(APPEND _cmake_import_check_files_for_hardware_interface::mock_components "${_IMPORT_PREFIX}/lib/libmock_components.so" )

# Import target "hardware_interface::hardware_interface" for configuration ""
set_property(TARGET hardware_interface::hardware_interface APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(hardware_interface::hardware_interface PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libhardware_interface.so"
  IMPORTED_SONAME_NOCONFIG "libhardware_interface.so"
  )

list(APPEND _cmake_import_check_targets hardware_interface::hardware_interface )
list(APPEND _cmake_import_check_files_for_hardware_interface::hardware_interface "${_IMPORT_PREFIX}/lib/libhardware_interface.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
