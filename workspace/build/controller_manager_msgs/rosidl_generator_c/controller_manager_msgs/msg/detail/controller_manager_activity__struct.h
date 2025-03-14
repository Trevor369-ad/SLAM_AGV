// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__STRUCT_H_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'controllers'
// Member 'hardware_components'
#include "controller_manager_msgs/msg/detail/named_lifecycle_state__struct.h"

/// Struct defined in msg/ControllerManagerActivity in the package controller_manager_msgs.
/**
  * This message is used to provide the activity within the controller manager regarding the change in state of controllers and hardware interfaces
 */
typedef struct controller_manager_msgs__msg__ControllerManagerActivity
{
  /// The header is used to provide timestamp information
  std_msgs__msg__Header header;
  /// The current state of the controllers
  controller_manager_msgs__msg__NamedLifecycleState__Sequence controllers;
  /// The current state of the hardware components
  controller_manager_msgs__msg__NamedLifecycleState__Sequence hardware_components;
} controller_manager_msgs__msg__ControllerManagerActivity;

// Struct for a sequence of controller_manager_msgs__msg__ControllerManagerActivity.
typedef struct controller_manager_msgs__msg__ControllerManagerActivity__Sequence
{
  controller_manager_msgs__msg__ControllerManagerActivity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} controller_manager_msgs__msg__ControllerManagerActivity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__STRUCT_H_
