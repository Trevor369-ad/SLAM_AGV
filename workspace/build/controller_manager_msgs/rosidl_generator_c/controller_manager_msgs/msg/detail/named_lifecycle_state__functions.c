// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from controller_manager_msgs:msg/NamedLifecycleState.idl
// generated code does not contain a copyright notice
#include "controller_manager_msgs/msg/detail/named_lifecycle_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `state`
#include "lifecycle_msgs/msg/detail/state__functions.h"

bool
controller_manager_msgs__msg__NamedLifecycleState__init(controller_manager_msgs__msg__NamedLifecycleState * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    controller_manager_msgs__msg__NamedLifecycleState__fini(msg);
    return false;
  }
  // state
  if (!lifecycle_msgs__msg__State__init(&msg->state)) {
    controller_manager_msgs__msg__NamedLifecycleState__fini(msg);
    return false;
  }
  return true;
}

void
controller_manager_msgs__msg__NamedLifecycleState__fini(controller_manager_msgs__msg__NamedLifecycleState * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // state
  lifecycle_msgs__msg__State__fini(&msg->state);
}

bool
controller_manager_msgs__msg__NamedLifecycleState__are_equal(const controller_manager_msgs__msg__NamedLifecycleState * lhs, const controller_manager_msgs__msg__NamedLifecycleState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // state
  if (!lifecycle_msgs__msg__State__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
controller_manager_msgs__msg__NamedLifecycleState__copy(
  const controller_manager_msgs__msg__NamedLifecycleState * input,
  controller_manager_msgs__msg__NamedLifecycleState * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // state
  if (!lifecycle_msgs__msg__State__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

controller_manager_msgs__msg__NamedLifecycleState *
controller_manager_msgs__msg__NamedLifecycleState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller_manager_msgs__msg__NamedLifecycleState * msg = (controller_manager_msgs__msg__NamedLifecycleState *)allocator.allocate(sizeof(controller_manager_msgs__msg__NamedLifecycleState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(controller_manager_msgs__msg__NamedLifecycleState));
  bool success = controller_manager_msgs__msg__NamedLifecycleState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
controller_manager_msgs__msg__NamedLifecycleState__destroy(controller_manager_msgs__msg__NamedLifecycleState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    controller_manager_msgs__msg__NamedLifecycleState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
controller_manager_msgs__msg__NamedLifecycleState__Sequence__init(controller_manager_msgs__msg__NamedLifecycleState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller_manager_msgs__msg__NamedLifecycleState * data = NULL;

  if (size) {
    data = (controller_manager_msgs__msg__NamedLifecycleState *)allocator.zero_allocate(size, sizeof(controller_manager_msgs__msg__NamedLifecycleState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = controller_manager_msgs__msg__NamedLifecycleState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        controller_manager_msgs__msg__NamedLifecycleState__fini(&data[i - 1]);
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
controller_manager_msgs__msg__NamedLifecycleState__Sequence__fini(controller_manager_msgs__msg__NamedLifecycleState__Sequence * array)
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
      controller_manager_msgs__msg__NamedLifecycleState__fini(&array->data[i]);
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

controller_manager_msgs__msg__NamedLifecycleState__Sequence *
controller_manager_msgs__msg__NamedLifecycleState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  controller_manager_msgs__msg__NamedLifecycleState__Sequence * array = (controller_manager_msgs__msg__NamedLifecycleState__Sequence *)allocator.allocate(sizeof(controller_manager_msgs__msg__NamedLifecycleState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = controller_manager_msgs__msg__NamedLifecycleState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
controller_manager_msgs__msg__NamedLifecycleState__Sequence__destroy(controller_manager_msgs__msg__NamedLifecycleState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    controller_manager_msgs__msg__NamedLifecycleState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
controller_manager_msgs__msg__NamedLifecycleState__Sequence__are_equal(const controller_manager_msgs__msg__NamedLifecycleState__Sequence * lhs, const controller_manager_msgs__msg__NamedLifecycleState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!controller_manager_msgs__msg__NamedLifecycleState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
controller_manager_msgs__msg__NamedLifecycleState__Sequence__copy(
  const controller_manager_msgs__msg__NamedLifecycleState__Sequence * input,
  controller_manager_msgs__msg__NamedLifecycleState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(controller_manager_msgs__msg__NamedLifecycleState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    controller_manager_msgs__msg__NamedLifecycleState * data =
      (controller_manager_msgs__msg__NamedLifecycleState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!controller_manager_msgs__msg__NamedLifecycleState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          controller_manager_msgs__msg__NamedLifecycleState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!controller_manager_msgs__msg__NamedLifecycleState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
