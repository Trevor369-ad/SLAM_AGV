// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from controller_manager_msgs:msg/NamedLifecycleState.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__TRAITS_HPP_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "controller_manager_msgs/msg/detail/named_lifecycle_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'state'
#include "lifecycle_msgs/msg/detail/state__traits.hpp"

namespace controller_manager_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NamedLifecycleState & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NamedLifecycleState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NamedLifecycleState & msg, bool use_flow_style = false)
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

}  // namespace controller_manager_msgs

namespace rosidl_generator_traits
{

[[deprecated("use controller_manager_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const controller_manager_msgs::msg::NamedLifecycleState & msg,
  std::ostream & out, size_t indentation = 0)
{
  controller_manager_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use controller_manager_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const controller_manager_msgs::msg::NamedLifecycleState & msg)
{
  return controller_manager_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<controller_manager_msgs::msg::NamedLifecycleState>()
{
  return "controller_manager_msgs::msg::NamedLifecycleState";
}

template<>
inline const char * name<controller_manager_msgs::msg::NamedLifecycleState>()
{
  return "controller_manager_msgs/msg/NamedLifecycleState";
}

template<>
struct has_fixed_size<controller_manager_msgs::msg::NamedLifecycleState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<controller_manager_msgs::msg::NamedLifecycleState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<controller_manager_msgs::msg::NamedLifecycleState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__TRAITS_HPP_
