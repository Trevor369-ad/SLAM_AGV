// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from controller_manager_msgs:msg/NamedLifecycleState.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__BUILDER_HPP_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "controller_manager_msgs/msg/detail/named_lifecycle_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace controller_manager_msgs
{

namespace msg
{

namespace builder
{

class Init_NamedLifecycleState_state
{
public:
  explicit Init_NamedLifecycleState_state(::controller_manager_msgs::msg::NamedLifecycleState & msg)
  : msg_(msg)
  {}
  ::controller_manager_msgs::msg::NamedLifecycleState state(::controller_manager_msgs::msg::NamedLifecycleState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controller_manager_msgs::msg::NamedLifecycleState msg_;
};

class Init_NamedLifecycleState_name
{
public:
  Init_NamedLifecycleState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NamedLifecycleState_state name(::controller_manager_msgs::msg::NamedLifecycleState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_NamedLifecycleState_state(msg_);
  }

private:
  ::controller_manager_msgs::msg::NamedLifecycleState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::controller_manager_msgs::msg::NamedLifecycleState>()
{
  return controller_manager_msgs::msg::builder::Init_NamedLifecycleState_name();
}

}  // namespace controller_manager_msgs

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__NAMED_LIFECYCLE_STATE__BUILDER_HPP_
