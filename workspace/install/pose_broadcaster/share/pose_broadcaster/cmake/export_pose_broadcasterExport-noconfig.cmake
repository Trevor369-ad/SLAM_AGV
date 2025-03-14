#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pose_broadcaster::pose_broadcaster" for configuration ""
set_property(TARGET pose_broadcaster::pose_broadcaster APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pose_broadcaster::pose_broadcaster PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpose_broadcaster.so"
  IMPORTED_SONAME_NOCONFIG "libpose_broadcaster.so"
  )

list(APPEND _cmake_import_check_targets pose_broadcaster::pose_broadcaster )
list(APPEND _cmake_import_check_files_for_pose_broadcaster::pose_broadcaster "${_IMPORT_PREFIX}/lib/libpose_broadcaster.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
