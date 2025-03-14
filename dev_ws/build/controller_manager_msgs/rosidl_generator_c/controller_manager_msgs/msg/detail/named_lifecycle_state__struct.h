// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from controller_manager_msgs:msg/NamedLifecycleState.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__STRUCT_H_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'state'
#include "lifecycle_msgs/msg/detail/state__struct.h"

/// Struct defined in msg/NamedLifecycleState in the package controller_manager_msgs.
/**
  * This message is used to provide information about the lifecycle state of the controller or the hardware components
 */
typedef struct controller_manager_msgs__msg__NamedLifecycleState
{
  /// The name of the controller or hardware interface
  rosidl_runtime_c__String name;
  /// The current lifecycle state of the controller or hardware components
  lifecycle_msgs__msg__State state;
} controller_manager_msgs__msg__NamedLifecycleState;

// Struct for a sequence of controller_manager_msgs__msg__NamedLifecycleState.
typedef struct controller_manager_msgs__msg__NamedLifecycleState__Sequence
{
  controller_manager_msgs__msg__NamedLifecycleState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} controller_manager_msgs__msg__NamedLifecycleState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__STRUCT_H_
