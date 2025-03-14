// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "controller_manager_msgs/msg/detail/controller_manager_activity__rosidl_typesupport_introspection_c.h"
#include "controller_manager_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "controller_manager_msgs/msg/detail/controller_manager_activity__functions.h"
#include "controller_manager_msgs/msg/detail/controller_manager_activity__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `controllers`
// Member `hardware_components`
#include "controller_manager_msgs/msg/named_lifecycle_state.h"
// Member `controllers`
// Member `hardware_components`
#include "controller_manager_msgs/msg/detail/named_lifecycle_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  controller_manager_msgs__msg__ControllerManagerActivity__init(message_memory);
}

void controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_fini_function(void * message_memory)
{
  controller_manager_msgs__msg__ControllerManagerActivity__fini(message_memory);
}

size_t controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__size_function__ControllerManagerActivity__controllers(
  const void * untyped_member)
{
  const controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (const controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  return member->size;
}

const void * controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_const_function__ControllerManagerActivity__controllers(
  const void * untyped_member, size_t index)
{
  const controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (const controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_function__ControllerManagerActivity__controllers(
  void * untyped_member, size_t index)
{
  controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  return &member->data[index];
}

void controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__fetch_function__ControllerManagerActivity__controllers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const controller_manager_msgs__msg__NamedLifecycleState * item =
    ((const controller_manager_msgs__msg__NamedLifecycleState *)
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_const_function__ControllerManagerActivity__controllers(untyped_member, index));
  controller_manager_msgs__msg__NamedLifecycleState * value =
    (controller_manager_msgs__msg__NamedLifecycleState *)(untyped_value);
  *value = *item;
}

void controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__assign_function__ControllerManagerActivity__controllers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  controller_manager_msgs__msg__NamedLifecycleState * item =
    ((controller_manager_msgs__msg__NamedLifecycleState *)
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_function__ControllerManagerActivity__controllers(untyped_member, index));
  const controller_manager_msgs__msg__NamedLifecycleState * value =
    (const controller_manager_msgs__msg__NamedLifecycleState *)(untyped_value);
  *item = *value;
}

bool controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__resize_function__ControllerManagerActivity__controllers(
  void * untyped_member, size_t size)
{
  controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  controller_manager_msgs__msg__NamedLifecycleState__Sequence__fini(member);
  return controller_manager_msgs__msg__NamedLifecycleState__Sequence__init(member, size);
}

size_t controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__size_function__ControllerManagerActivity__hardware_components(
  const void * untyped_member)
{
  const controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (const controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  return member->size;
}

const void * controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_const_function__ControllerManagerActivity__hardware_components(
  const void * untyped_member, size_t index)
{
  const controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (const controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_function__ControllerManagerActivity__hardware_components(
  void * untyped_member, size_t index)
{
  controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  return &member->data[index];
}

void controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__fetch_function__ControllerManagerActivity__hardware_components(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const controller_manager_msgs__msg__NamedLifecycleState * item =
    ((const controller_manager_msgs__msg__NamedLifecycleState *)
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_const_function__ControllerManagerActivity__hardware_components(untyped_member, index));
  controller_manager_msgs__msg__NamedLifecycleState * value =
    (controller_manager_msgs__msg__NamedLifecycleState *)(untyped_value);
  *value = *item;
}

void controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__assign_function__ControllerManagerActivity__hardware_components(
  void * untyped_member, size_t index, const void * untyped_value)
{
  controller_manager_msgs__msg__NamedLifecycleState * item =
    ((controller_manager_msgs__msg__NamedLifecycleState *)
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_function__ControllerManagerActivity__hardware_components(untyped_member, index));
  const controller_manager_msgs__msg__NamedLifecycleState * value =
    (const controller_manager_msgs__msg__NamedLifecycleState *)(untyped_value);
  *item = *value;
}

bool controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__resize_function__ControllerManagerActivity__hardware_components(
  void * untyped_member, size_t size)
{
  controller_manager_msgs__msg__NamedLifecycleState__Sequence * member =
    (controller_manager_msgs__msg__NamedLifecycleState__Sequence *)(untyped_member);
  controller_manager_msgs__msg__NamedLifecycleState__Sequence__fini(member);
  return controller_manager_msgs__msg__NamedLifecycleState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(controller_manager_msgs__msg__ControllerManagerActivity, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "controllers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(controller_manager_msgs__msg__ControllerManagerActivity, controllers),  // bytes offset in struct
    NULL,  // default value
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__size_function__ControllerManagerActivity__controllers,  // size() function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_const_function__ControllerManagerActivity__controllers,  // get_const(index) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_function__ControllerManagerActivity__controllers,  // get(index) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__fetch_function__ControllerManagerActivity__controllers,  // fetch(index, &value) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__assign_function__ControllerManagerActivity__controllers,  // assign(index, value) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__resize_function__ControllerManagerActivity__controllers  // resize(index) function pointer
  },
  {
    "hardware_components",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(controller_manager_msgs__msg__ControllerManagerActivity, hardware_components),  // bytes offset in struct
    NULL,  // default value
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__size_function__ControllerManagerActivity__hardware_components,  // size() function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_const_function__ControllerManagerActivity__hardware_components,  // get_const(index) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__get_function__ControllerManagerActivity__hardware_components,  // get(index) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__fetch_function__ControllerManagerActivity__hardware_components,  // fetch(index, &value) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__assign_function__ControllerManagerActivity__hardware_components,  // assign(index, value) function pointer
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__resize_function__ControllerManagerActivity__hardware_components  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_members = {
  "controller_manager_msgs__msg",  // message namespace
  "ControllerManagerActivity",  // message name
  3,  // number of fields
  sizeof(controller_manager_msgs__msg__ControllerManagerActivity),
  controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_member_array,  // message members
  controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_init_function,  // function to initialize message memory (memory has to be allocated)
  controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_type_support_handle = {
  0,
  &controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_controller_manager_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controller_manager_msgs, msg, ControllerManagerActivity)() {
  controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controller_manager_msgs, msg, NamedLifecycleState)();
  controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controller_manager_msgs, msg, NamedLifecycleState)();
  if (!controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_type_support_handle.typesupport_identifier) {
    controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &controller_manager_msgs__msg__ControllerManagerActivity__rosidl_typesupport_introspection_c__ControllerManagerActivity_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
