#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "joint_limits::joint_limiter_interface" for configuration ""
set_property(TARGET joint_limits::joint_limiter_interface APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(joint_limits::joint_limiter_interface PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libjoint_limiter_interface.so"
  IMPORTED_SONAME_NOCONFIG "libjoint_limiter_interface.so"
  )

list(APPEND _cmake_import_check_targets joint_limits::joint_limiter_interface )
list(APPEND _cmake_import_check_files_for_joint_limits::joint_limiter_interface "${_IMPORT_PREFIX}/lib/libjoint_limiter_interface.so" )

# Import target "joint_limits::joint_saturation_limiter" for configuration ""
set_property(TARGET joint_limits::joint_saturation_limiter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(joint_limits::joint_saturation_limiter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libjoint_saturation_limiter.so"
  IMPORTED_SONAME_NOCONFIG "libjoint_saturation_limiter.so"
  )

list(APPEND _cmake_import_check_targets joint_limits::joint_saturation_limiter )
list(APPEND _cmake_import_check_files_for_joint_limits::joint_saturation_limiter "${_IMPORT_PREFIX}/lib/libjoint_saturation_limiter.so" )

# Import target "joint_limits::joint_limits_helpers" for configuration ""
set_property(TARGET joint_limits::joint_limits_helpers APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(joint_limits::joint_limits_helpers PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libjoint_limits_helpers.so"
  IMPORTED_SONAME_NOCONFIG "libjoint_limits_helpers.so"
  )

list(APPEND _cmake_import_check_targets joint_limits::joint_limits_helpers )
list(APPEND _cmake_import_check_files_for_joint_limits::joint_limits_helpers "${_IMPORT_PREFIX}/lib/libjoint_limits_helpers.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
