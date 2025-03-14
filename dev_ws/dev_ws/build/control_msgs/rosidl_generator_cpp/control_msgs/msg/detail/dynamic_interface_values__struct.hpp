// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_msgs:msg/DynamicInterfaceValues.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__STRUCT_HPP_
#define CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__STRUCT_HPP_

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
// Member 'states'
// Member 'commands'
#include "control_msgs/msg/detail/interface_value__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__control_msgs__msg__DynamicInterfaceValues __attribute__((deprecated))
#else
# define DEPRECATED__control_msgs__msg__DynamicInterfaceValues __declspec(deprecated)
#endif

namespace control_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DynamicInterfaceValues_
{
  using Type = DynamicInterfaceValues_<ContainerAllocator>;

  explicit DynamicInterfaceValues_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    states(_init),
    commands(_init)
  {
    (void)_init;
  }

  explicit DynamicInterfaceValues_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    states(_alloc, _init),
    commands(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _states_type =
    control_msgs::msg::InterfaceValue_<ContainerAllocator>;
  _states_type states;
  using _commands_type =
    control_msgs::msg::InterfaceValue_<ContainerAllocator>;
  _commands_type commands;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__states(
    const control_msgs::msg::InterfaceValue_<ContainerAllocator> & _arg)
  {
    this->states = _arg;
    return *this;
  }
  Type & set__commands(
    const control_msgs::msg::InterfaceValue_<ContainerAllocator> & _arg)
  {
    this->commands = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_msgs__msg__DynamicInterfaceValues
    std::shared_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_msgs__msg__DynamicInterfaceValues
    std::shared_ptr<control_msgs::msg::DynamicInterfaceValues_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DynamicInterfaceValues_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->states != other.states) {
      return false;
    }
    if (this->commands != other.commands) {
      return false;
    }
    return true;
  }
  bool operator!=(const DynamicInterfaceValues_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DynamicInterfaceValues_

// alias to use template instance with default allocator
using DynamicInterfaceValues =
  control_msgs::msg::DynamicInterfaceValues_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace control_msgs

#endif  // CONTROL_MSGS__MSG__DETAIL__DYNAMIC_INTERFACE_VALUES__STRUCT_HPP_
