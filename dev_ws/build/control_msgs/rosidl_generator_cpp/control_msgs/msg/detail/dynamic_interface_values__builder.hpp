// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_msgs:msg/DynamicInterfaceValues.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__BUILDER_HPP_
#define CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_msgs/msg/detail/dynamic_interface_values__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_msgs
{

namespace msg
{

namespace builder
{

class Init_DynamicInterfaceValues_commands
{
public:
  explicit Init_DynamicInterfaceValues_commands(::control_msgs::msg::DynamicInterfaceValues & msg)
  : msg_(msg)
  {}
  ::control_msgs::msg::DynamicInterfaceValues commands(::control_msgs::msg::DynamicInterfaceValues::_commands_type arg)
  {
    msg_.commands = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_msgs::msg::DynamicInterfaceValues msg_;
};

class Init_DynamicInterfaceValues_states
{
public:
  explicit Init_DynamicInterfaceValues_states(::control_msgs::msg::DynamicInterfaceValues & msg)
  : msg_(msg)
  {}
  Init_DynamicInterfaceValues_commands states(::control_msgs::msg::DynamicInterfaceValues::_states_type arg)
  {
    msg_.states = std::move(arg);
    return Init_DynamicInterfaceValues_commands(msg_);
  }

private:
  ::control_msgs::msg::DynamicInterfaceValues msg_;
};

class Init_DynamicInterfaceValues_header
{
public:
  Init_DynamicInterfaceValues_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DynamicInterfaceValues_states header(::control_msgs::msg::DynamicInterfaceValues::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DynamicInterfaceValues_states(msg_);
  }

private:
  ::control_msgs::msg::DynamicInterfaceValues msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_msgs::msg::DynamicInterfaceValues>()
{
  return control_msgs::msg::builder::Init_DynamicInterfaceValues_header();
}

}  // namespace control_msgs

#endif  // CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__BUILDER_HPP_
