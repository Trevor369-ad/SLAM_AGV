// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from control_msgs:msg/DynamicInterfaceValues.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "control_msgs/msg/detail/dynamic_interface_values__rosidl_typesupport_introspection_c.h"
#include "control_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "control_msgs/msg/detail/dynamic_interface_values__functions.h"
#include "control_msgs/msg/detail/dynamic_interface_values__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `states`
// Member `commands`
#include "control_msgs/msg/interface_value.h"
// Member `states`
// Member `commands`
#include "control_msgs/msg/detail/interface_value__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_msgs__msg__DynamicInterfaceValues__init(message_memory);
}

void control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_fini_function(void * message_memory)
{
  control_msgs__msg__DynamicInterfaceValues__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_msgs__msg__DynamicInterfaceValues, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_msgs__msg__DynamicInterfaceValues, states),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "commands",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_msgs__msg__DynamicInterfaceValues, commands),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_members = {
  "control_msgs__msg",  // message namespace
  "DynamicInterfaceValues",  // message name
  3,  // number of fields
  sizeof(control_msgs__msg__DynamicInterfaceValues),
  control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_member_array,  // message members
  control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_init_function,  // function to initialize message memory (memory has to be allocated)
  control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_type_support_handle = {
  0,
  &control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_msgs, msg, DynamicInterfaceValues)() {
  control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_msgs, msg, InterfaceValue)();
  control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_msgs, msg, InterfaceValue)();
  if (!control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_type_support_handle.typesupport_identifier) {
    control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_msgs__msg__DynamicInterfaceValues__rosidl_typesupport_introspection_c__DynamicInterfaceValues_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
