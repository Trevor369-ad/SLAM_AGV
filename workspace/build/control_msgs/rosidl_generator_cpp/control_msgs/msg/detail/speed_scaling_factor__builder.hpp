// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_msgs:msg/SpeedScalingFactor.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__BUILDER_HPP_
#define CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_msgs/msg/detail/speed_scaling_factor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_msgs
{

namespace msg
{

namespace builder
{

class Init_SpeedScalingFactor_factor
{
public:
  Init_SpeedScalingFactor_factor()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::control_msgs::msg::SpeedScalingFactor factor(::control_msgs::msg::SpeedScalingFactor::_factor_type arg)
  {
    msg_.factor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_msgs::msg::SpeedScalingFactor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_msgs::msg::SpeedScalingFactor>()
{
  return control_msgs::msg::builder::Init_SpeedScalingFactor_factor();
}

}  // namespace control_msgs

#endif  // CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__BUILDER_HPP_
