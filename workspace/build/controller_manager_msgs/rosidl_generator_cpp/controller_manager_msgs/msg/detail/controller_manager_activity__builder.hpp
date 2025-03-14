// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__BUILDER_HPP_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "controller_manager_msgs/msg/detail/controller_manager_activity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace controller_manager_msgs
{

namespace msg
{

namespace builder
{

class Init_ControllerManagerActivity_hardware_components
{
public:
  explicit Init_ControllerManagerActivity_hardware_components(::controller_manager_msgs::msg::ControllerManagerActivity & msg)
  : msg_(msg)
  {}
  ::controller_manager_msgs::msg::ControllerManagerActivity hardware_components(::controller_manager_msgs::msg::ControllerManagerActivity::_hardware_components_type arg)
  {
    msg_.hardware_components = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controller_manager_msgs::msg::ControllerManagerActivity msg_;
};

class Init_ControllerManagerActivity_controllers
{
public:
  explicit Init_ControllerManagerActivity_controllers(::controller_manager_msgs::msg::ControllerManagerActivity & msg)
  : msg_(msg)
  {}
  Init_ControllerManagerActivity_hardware_components controllers(::controller_manager_msgs::msg::ControllerManagerActivity::_controllers_type arg)
  {
    msg_.controllers = std::move(arg);
    return Init_ControllerManagerActivity_hardware_components(msg_);
  }

private:
  ::controller_manager_msgs::msg::ControllerManagerActivity msg_;
};

class Init_ControllerManagerActivity_header
{
public:
  Init_ControllerManagerActivity_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControllerManagerActivity_controllers header(::controller_manager_msgs::msg::ControllerManagerActivity::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControllerManagerActivity_controllers(msg_);
  }

private:
  ::controller_manager_msgs::msg::ControllerManagerActivity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::controller_manager_msgs::msg::ControllerManagerActivity>()
{
  return controller_manager_msgs::msg::builder::Init_ControllerManagerActivity_header();
}

}  // namespace controller_manager_msgs

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__BUILDER_HPP_
