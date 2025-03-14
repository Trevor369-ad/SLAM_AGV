// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice
#include "controller_manager_msgs/msg/detail/controller_manager_activity__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `controllers`
// Member `hardware_components`
#include "controller_manager_msgs/msg/detail/named_lifecycle_state__functions.h"

bool
controller_manager_msgs__msg__ControllerManagerActivity__init(controller_manager_msgs__msg__ControllerManagerActivity * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    controller_manager_msgs__msg__ControllerManagerActivity__fini(msg);
    return false;
  }
  // controllers
  if (!controller_manager_msgs__msg__NamedLifecycleState__Sequence__init(&msg->controllers, 0)) {
    controller_manager_msgs__msg__ControllerManagerActivity__fini(msg);
    return false;
  }
  // hardware_components
  if (!controller_manager_msgs__msg__NamedLifecycleState__Sequence__init(&msg->hardware_components, 0)) {
    controller_manager_msgs__msg__ControllerManagerActivity__fini(msg);
    return false;
  }
  return true;
}

void
controller_manager_msgs__msg__ControllerManagerActivity__fini(controller_manager_msgs__msg__ControllerManagerActivity * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // controllers
  controller_manager_msgs__msg__NamedLifecycleState__Sequence__fini(&msg->controllers);
  // hardware_components
  controller_manager_msgs__msg__NamedLifecycleState__Sequence__fini(&msg->hardware_components);
}

bool
controller_manager_msgs__msg__ControllerManagerActivity__are_equal(const controller_manager_msgs__msg__ControllerManagerActivity * lhs, const controller_manager_msgs__msg__ControllerManagerActivity * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // controllers
  if (!controller_manager_msgs__msg__NamedLifecycleState__Sequence__are_equal(
      &(lhs->controllers), &(rhs->controllers)))
  {
    return false;
  }
  // hardware_components
  if (!controller_manager_msgs__msg__NamedLifecycleState__Sequence__are_equal(
      &(lhs->hardware_components), &(rhs->hardware_components)))
  {
    return false;
  }
  return true;
}

bool
controller_manager_msgs__msg__ControllerManagerActivity__copy(
  const controller_manager_msgs__msg__ControllerManagerActivity * input,
  controller_manager_msgs__msg__ControllerManagerActivity * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // controllers
  if (!controller_manager_msgs__msg__NamedLifecycleState__Sequence__copy(
      &(input->controllers), &(output->controllers)))
  {
    return false;
  }
  // hardware_components
  if (!controller_manager_msgs__msg__NamedLifecycleState__Sequence__copy(
      &(input->hardware_components), &(output->hardware_components)))
  {
    return false;
  }
  return true;
}

controller_manager_msgs__msg__ControllerManagerActivity *
controller_manager_msgs__msg__ControllerManagerActivity__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller_manager_msgs__msg__ControllerManagerActivity * msg = (controller_manager_msgs__msg__ControllerManagerActivity *)allocator.allocate(sizeof(controller_manager_msgs__msg__ControllerManagerActivity), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(controller_manager_msgs__msg__ControllerManagerActivity));
  bool success = controller_manager_msgs__msg__ControllerManagerActivity__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
controller_manager_msgs__msg__ControllerManagerActivity__destroy(controller_manager_msgs__msg__ControllerManagerActivity * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    controller_manager_msgs__msg__ControllerManagerActivity__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__init(controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller_manager_msgs__msg__ControllerManagerActivity * data = NULL;

  if (size) {
    data = (controller_manager_msgs__msg__ControllerManagerActivity *)allocator.zero_allocate(size, sizeof(controller_manager_msgs__msg__ControllerManagerActivity), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = controller_manager_msgs__msg__ControllerManagerActivity__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        controller_manager_msgs__msg__ControllerManagerActivity__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__fini(controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      controller_manager_msgs__msg__ControllerManagerActivity__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

controller_manager_msgs__msg__ControllerManagerActivity__Sequence *
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array = (controller_manager_msgs__msg__ControllerManagerActivity__Sequence *)allocator.allocate(sizeof(controller_manager_msgs__msg__ControllerManagerActivity__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = controller_manager_msgs__msg__ControllerManagerActivity__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__destroy(controller_manager_msgs__msg__ControllerManagerActivity__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    controller_manager_msgs__msg__ControllerManagerActivity__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__are_equal(const controller_manager_msgs__msg__ControllerManagerActivity__Sequence * lhs, const controller_manager_msgs__msg__ControllerManagerActivity__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!controller_manager_msgs__msg__ControllerManagerActivity__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
controller_manager_msgs__msg__ControllerManagerActivity__Sequence__copy(
  const controller_manager_msgs__msg__ControllerManagerActivity__Sequence * input,
  controller_manager_msgs__msg__ControllerManagerActivity__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(controller_manager_msgs__msg__ControllerManagerActivity);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    controller_manager_msgs__msg__ControllerManagerActivity * data =
      (controller_manager_msgs__msg__ControllerManagerActivity *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!controller_manager_msgs__msg__ControllerManagerActivity__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          controller_manager_msgs__msg__ControllerManagerActivity__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!controller_manager_msgs__msg__ControllerManagerActivity__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
