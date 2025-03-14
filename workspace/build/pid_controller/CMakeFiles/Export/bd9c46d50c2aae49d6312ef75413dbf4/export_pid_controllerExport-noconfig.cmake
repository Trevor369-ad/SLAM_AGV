#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pid_controller::pid_controller" for configuration ""
set_property(TARGET pid_controller::pid_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pid_controller::pid_controller PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpid_controller.so"
  IMPORTED_SONAME_NOCONFIG "libpid_controller.so"
  )

list(APPEND _cmake_import_check_targets pid_controller::pid_controller )
list(APPEND _cmake_import_check_files_for_pid_controller::pid_controller "${_IMPORT_PREFIX}/lib/libpid_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
