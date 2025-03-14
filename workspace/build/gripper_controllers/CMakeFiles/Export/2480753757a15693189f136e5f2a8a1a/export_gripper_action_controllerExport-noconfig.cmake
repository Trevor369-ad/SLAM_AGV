#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gripper_controllers::gripper_action_controller" for configuration ""
set_property(TARGET gripper_controllers::gripper_action_controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(gripper_controllers::gripper_action_controller PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libgripper_action_controller.so"
  IMPORTED_SONAME_NOCONFIG "libgripper_action_controller.so"
  )

list(APPEND _cmake_import_check_targets gripper_controllers::gripper_action_controller )
list(APPEND _cmake_import_check_files_for_gripper_controllers::gripper_action_controller "${_IMPORT_PREFIX}/lib/libgripper_action_controller.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
