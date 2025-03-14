// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__TRAITS_HPP_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "controller_manager_msgs/msg/detail/controller_manager_activity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'controllers'
// Member 'hardware_components'
#include "controller_manager_msgs/msg/detail/named_lifecycle_state__traits.hpp"

namespace controller_manager_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControllerManagerActivity & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: controllers
  {
    if (msg.controllers.size() == 0) {
      out << "controllers: []";
    } else {
      out << "controllers: [";
      size_t pending_items = msg.controllers.size();
      for (auto item : msg.controllers) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hardware_components
  {
    if (msg.hardware_components.size() == 0) {
      out << "hardware_components: []";
    } else {
      out << "hardware_components: [";
      size_t pending_items = msg.hardware_components.size();
      for (auto item : msg.hardware_components) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControllerManagerActivity & msg,
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

  // member: controllers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.controllers.size() == 0) {
      out << "controllers: []\n";
    } else {
      out << "controllers:\n";
      for (auto item : msg.controllers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: hardware_components
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hardware_components.size() == 0) {
      out << "hardware_components: []\n";
    } else {
      out << "hardware_components:\n";
      for (auto item : msg.hardware_components) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControllerManagerActivity & msg, bool use_flow_style = false)
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
  const controller_manager_msgs::msg::ControllerManagerActivity & msg,
  std::ostream & out, size_t indentation = 0)
{
  controller_manager_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use controller_manager_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const controller_manager_msgs::msg::ControllerManagerActivity & msg)
{
  return controller_manager_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<controller_manager_msgs::msg::ControllerManagerActivity>()
{
  return "controller_manager_msgs::msg::ControllerManagerActivity";
}

template<>
inline const char * name<controller_manager_msgs::msg::ControllerManagerActivity>()
{
  return "controller_manager_msgs/msg/ControllerManagerActivity";
}

template<>
struct has_fixed_size<controller_manager_msgs::msg::ControllerManagerActivity>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<controller_manager_msgs::msg::ControllerManagerActivity>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<controller_manager_msgs::msg::ControllerManagerActivity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__TRAITS_HPP_
