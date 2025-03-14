// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from controller_manager_msgs:msg/ControllerManagerActivity.idl
// generated code does not contain a copyright notice

#ifndef CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__STRUCT_HPP_
#define CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'controllers'
// Member 'hardware_components'
#include "controller_manager_msgs/msg/detail/named_lifecycle_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__controller_manager_msgs__msg__ControllerManagerActivity __attribute__((deprecated))
#else
# define DEPRECATED__controller_manager_msgs__msg__ControllerManagerActivity __declspec(deprecated)
#endif

namespace controller_manager_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControllerManagerActivity_
{
  using Type = ControllerManagerActivity_<ContainerAllocator>;

  explicit ControllerManagerActivity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit ControllerManagerActivity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _controllers_type =
    std::vector<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>>>;
  _controllers_type controllers;
  using _hardware_components_type =
    std::vector<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>>>;
  _hardware_components_type hardware_components;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__controllers(
    const std::vector<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>>> & _arg)
  {
    this->controllers = _arg;
    return *this;
  }
  Type & set__hardware_components(
    const std::vector<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controller_manager_msgs::msg::NamedLifecycleState_<ContainerAllocator>>> & _arg)
  {
    this->hardware_components = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator> *;
  using ConstRawPtr =
    const controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__controller_manager_msgs__msg__ControllerManagerActivity
    std::shared_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__controller_manager_msgs__msg__ControllerManagerActivity
    std::shared_ptr<controller_manager_msgs::msg::ControllerManagerActivity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControllerManagerActivity_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->controllers != other.controllers) {
      return false;
    }
    if (this->hardware_components != other.hardware_components) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControllerManagerActivity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControllerManagerActivity_

// alias to use template instance with default allocator
using ControllerManagerActivity =
  controller_manager_msgs::msg::ControllerManagerActivity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace controller_manager_msgs

#endif  // CONTROLLER_MANAGER_MSGS__MSG__DETAIL__CONTROLLER_MANAGER_ACTIVITY__STRUCT_HPP_
