// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_msgs:msg/DynamicInterfaceValues.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__TRAITS_HPP_
#define CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_msgs/msg/detail/dynamic_interface_values__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'states'
// Member 'commands'
#include "control_msgs/msg/detail/interface_value__traits.hpp"

namespace control_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DynamicInterfaceValues & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: states
  {
    out << "states: ";
    to_flow_style_yaml(msg.states, out);
    out << ", ";
  }

  // member: commands
  {
    out << "commands: ";
    to_flow_style_yaml(msg.commands, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DynamicInterfaceValues & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "states:\n";
    to_block_style_yaml(msg.states, out, indentation + 2);
  }

  // member: commands
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "commands:\n";
    to_block_style_yaml(msg.commands, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DynamicInterfaceValues & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use control_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_msgs::msg::DynamicInterfaceValues & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const control_msgs::msg::DynamicInterfaceValues & msg)
{
  return control_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control_msgs::msg::DynamicInterfaceValues>()
{
  return "control_msgs::msg::DynamicInterfaceValues";
}

template<>
inline const char * name<control_msgs::msg::DynamicInterfaceValues>()
{
  return "control_msgs/msg/DynamicInterfaceValues";
}

template<>
struct has_fixed_size<control_msgs::msg::DynamicInterfaceValues>
  : std::integral_constant<bool, has_fixed_size<control_msgs::msg::InterfaceValue>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<control_msgs::msg::DynamicInterfaceValues>
  : std::integral_constant<bool, has_bounded_size<control_msgs::msg::InterfaceValue>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<control_msgs::msg::DynamicInterfaceValues>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__TRAITS_HPP_
