// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__FUNCTIONS_H_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "controller_manager_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "controller_manager_msgs/msg/detail/controller_manager_activity__struct.h"

/// Initialize msg/ControllerManagerActivity message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * controller_manager_msgs__msg__ControllerManagerActivity
 * )) before or use
 * controller_manager_msgs__msg__ControllerManagerActivity__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
bool
controller_manager_msgs__msg__ControllerManagerActivity__init(controller_manager_msgs__msg__ControllerManagerActivity * msg);

/// Finalize msg/ControllerManagerActivity message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
void
controller_manager_msgs__msg__ControllerManagerActivity__fini(controller_manager_msgs__msg__ControllerManagerActivity * msg);

/// Create msg/ControllerManagerActivity message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * controller_manager_msgs__msg__ControllerManagerActivity__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
controller_manager_msgs__msg__ControllerManagerActivity *
controller_manager_msgs__msg__ControllerManagerActivity__create();

/// Destroy msg/ControllerManagerActivity message.
/**
 * It calls
 * controller_manager_msgs__msg__ControllerManagerActivity__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
void
controller_manager_msgs__msg__ControllerManagerActivity__destroy(controller_manager_msgs__msg__ControllerManagerActivity * msg);

/// Check for msg/ControllerManagerActivity message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
bool
controller_manager_msgs__msg__ControllerManagerActivity__are_equal(const controller_manager_msgs__msg__ControllerManagerActivity * lhs, const controller_manager_msgs__msg__ControllerManagerActivity * rhs);

/// Copy a msg/ControllerManagerActivity message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
bool
controller_manager_msgs__msg__ControllerManagerActivity__copy(
  const controller_manager_msgs__msg__ControllerManagerActivity * input,
  controller_manager_msgs__msg__ControllerManagerActivity * output);

/// Initialize array of msg/ControllerManagerActivity messages.
/**
 * It allocates the memory for the number of elements and calls
 * controller_manager_msgs__msg__ControllerManagerActivity__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
bool
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__init(controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array, size_t size);

/// Finalize array of msg/ControllerManagerActivity messages.
/**
 * It calls
 * controller_manager_msgs__msg__ControllerManagerActivity__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
void
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__fini(controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array);

/// Create array of msg/ControllerManagerActivity messages.
/**
 * It allocates the memory for the array and calls
 * controller_manager_msgs__msg__ControllerManagerActivity__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
controller_manager_msgs__msg__ControllerManagerActivity__Sequence *
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__create(size_t size);

/// Destroy array of msg/ControllerManagerActivity messages.
/**
 * It calls
 * controller_manager_msgs__msg__ControllerManagerActivity__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
void
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__destroy(controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array);

/// Check for msg/ControllerManagerActivity message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
bool
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__are_equal(const controller_manager_msgs__msg__ControllerManagerActivity__Sequence * lhs, const controller_manager_msgs__msg__ControllerManagerActivity__Sequence * rhs);

/// Copy an array of msg/ControllerManagerActivity messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_controller_manager_msgs
bool
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__copy(
  const controller_manager_msgs__msg__ControllerManagerActivity__Sequence * input,
  controller_manager_msgs__msg__ControllerManagerActivity__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__FUNCTIONS_H_
