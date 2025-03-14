#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "range_sensor_broadcaster::range_sensor_broadcaster" for configuration ""
set_property(TARGET range_sensor_broadcaster::range_sensor_broadcaster APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(range_sensor_broadcaster::range_sensor_broadcaster PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librange_sensor_broadcaster.so"
  IMPORTED_SONAME_NOCONFIG "librange_sensor_broadcaster.so"
  )

list(APPEND _cmake_import_check_targets range_sensor_broadcaster::range_sensor_broadcaster )
list(APPEND _cmake_import_check_files_for_range_sensor_broadcaster::range_sensor_broadcaster "${_IMPORT_PREFIX}/lib/librange_sensor_broadcaster.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
