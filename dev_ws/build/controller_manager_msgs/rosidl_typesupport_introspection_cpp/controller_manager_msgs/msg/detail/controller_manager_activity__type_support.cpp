// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "controller_manager_msgs/msg/detail/controller_manager_activity__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace controller_manager_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ControllerManagerActivity_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) controller_manager_msgs::msg::ControllerManagerActivity(_init);
}

void ControllerManagerActivity_fini_function(void * message_memory)
{
  auto typed_message = static_cast<controller_manager_msgs::msg::ControllerManagerActivity *>(message_memory);
  typed_message->~ControllerManagerActivity();
}

size_t size_function__ControllerManagerActivity__controllers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ControllerManagerActivity__controllers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerManagerActivity__controllers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerManagerActivity__controllers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const controller_manager_msgs::msg::NamedLifecycleState *>(
    get_const_function__ControllerManagerActivity__controllers(untyped_member, index));
  auto & value = *reinterpret_cast<controller_manager_msgs::msg::NamedLifecycleState *>(untyped_value);
  value = item;
}

void assign_function__ControllerManagerActivity__controllers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<controller_manager_msgs::msg::NamedLifecycleState *>(
    get_function__ControllerManagerActivity__controllers(untyped_member, index));
  const auto & value = *reinterpret_cast<const controller_manager_msgs::msg::NamedLifecycleState *>(untyped_value);
  item = value;
}

void resize_function__ControllerManagerActivity__controllers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ControllerManagerActivity__hardware_components(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ControllerManagerActivity__hardware_components(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  return &member[index];
}

void * get_function__ControllerManagerActivity__hardware_components(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  return &member[index];
}

void fetch_function__ControllerManagerActivity__hardware_components(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const controller_manager_msgs::msg::NamedLifecycleState *>(
    get_const_function__ControllerManagerActivity__hardware_components(untyped_member, index));
  auto & value = *reinterpret_cast<controller_manager_msgs::msg::NamedLifecycleState *>(untyped_value);
  value = item;
}

void assign_function__ControllerManagerActivity__hardware_components(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<controller_manager_msgs::msg::NamedLifecycleState *>(
    get_function__ControllerManagerActivity__hardware_components(untyped_member, index));
  const auto & value = *reinterpret_cast<const controller_manager_msgs::msg::NamedLifecycleState *>(untyped_value);
  item = value;
}

void resize_function__ControllerManagerActivity__hardware_components(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<controller_manager_msgs::msg::NamedLifecycleState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ControllerManagerActivity_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(controller_manager_msgs::msg::ControllerManagerActivity, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "controllers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<controller_manager_msgs::msg::NamedLifecycleState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(controller_manager_msgs::msg::ControllerManagerActivity, controllers),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerManagerActivity__controllers,  // size() function pointer
    get_const_function__ControllerManagerActivity__controllers,  // get_const(index) function pointer
    get_function__ControllerManagerActivity__controllers,  // get(index) function pointer
    fetch_function__ControllerManagerActivity__controllers,  // fetch(index, &value) function pointer
    assign_function__ControllerManagerActivity__controllers,  // assign(index, value) function pointer
    resize_function__ControllerManagerActivity__controllers  // resize(index) function pointer
  },
  {
    "hardware_components",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<controller_manager_msgs::msg::NamedLifecycleState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(controller_manager_msgs::msg::ControllerManagerActivity, hardware_components),  // bytes offset in struct
    nullptr,  // default value
    size_function__ControllerManagerActivity__hardware_components,  // size() function pointer
    get_const_function__ControllerManagerActivity__hardware_components,  // get_const(index) function pointer
    get_function__ControllerManagerActivity__hardware_components,  // get(index) function pointer
    fetch_function__ControllerManagerActivity__hardware_components,  // fetch(index, &value) function pointer
    assign_function__ControllerManagerActivity__hardware_components,  // assign(index, value) function pointer
    resize_function__ControllerManagerActivity__hardware_components  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ControllerManagerActivity_message_members = {
  "controller_manager_msgs::msg",  // message namespace
  "ControllerManagerActivity",  // message name
  3,  // number of fields
  sizeof(controller_manager_msgs::msg::ControllerManagerActivity),
  ControllerManagerActivity_message_member_array,  // message members
  ControllerManagerActivity_init_function,  // function to initialize message memory (memory has to be allocated)
  ControllerManagerActivity_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ControllerManagerActivity_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ControllerManagerActivity_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace controller_manager_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<controller_manager_msgs::msg::ControllerManagerActivity>()
{
  return &::controller_manager_msgs::msg::rosidl_typesupport_introspection_cpp::ControllerManagerActivity_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, controller_manager_msgs, msg, ControllerManagerActivity)() {
  return &::controller_manager_msgs::msg::rosidl_typesupport_introspection_cpp::ControllerManagerActivity_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
