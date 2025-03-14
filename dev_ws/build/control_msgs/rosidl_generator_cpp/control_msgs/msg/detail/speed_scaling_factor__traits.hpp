// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_msgs:msg/SpeedScalingFactor.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__TRAITS_HPP_
#define CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_msgs/msg/detail/speed_scaling_factor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpeedScalingFactor & msg,
  std::ostream & out)
{
  out << "{";
  // member: factor
  {
    out << "factor: ";
    rosidl_generator_traits::value_to_yaml(msg.factor, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpeedScalingFactor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: factor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "factor: ";
    rosidl_generator_traits::value_to_yaml(msg.factor, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpeedScalingFactor & msg, bool use_flow_style = false)
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
  const control_msgs::msg::SpeedScalingFactor & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const control_msgs::msg::SpeedScalingFactor & msg)
{
  return control_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control_msgs::msg::SpeedScalingFactor>()
{
  return "control_msgs::msg::SpeedScalingFactor";
}

template<>
inline const char * name<control_msgs::msg::SpeedScalingFactor>()
{
  return "control_msgs/msg/SpeedScalingFactor";
}

template<>
struct has_fixed_size<control_msgs::msg::SpeedScalingFactor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_msgs::msg::SpeedScalingFactor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_msgs::msg::SpeedScalingFactor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__TRAITS_HPP_
