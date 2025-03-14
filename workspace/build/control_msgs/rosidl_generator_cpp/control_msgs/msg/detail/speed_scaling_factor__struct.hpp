// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_msgs:msg/SpeedScalingFactor.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__STRUCT_HPP_
#define CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_msgs__msg__SpeedScalingFactor __attribute__((deprecated))
#else
# define DEPRECATED__control_msgs__msg__SpeedScalingFactor __declspec(deprecated)
#endif

namespace control_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpeedScalingFactor_
{
  using Type = SpeedScalingFactor_<ContainerAllocator>;

  explicit SpeedScalingFactor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->factor = 0.0;
    }
  }

  explicit SpeedScalingFactor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->factor = 0.0;
    }
  }

  // field types and members
  using _factor_type =
    double;
  _factor_type factor;

  // setters for named parameter idiom
  Type & set__factor(
    const double & _arg)
  {
    this->factor = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_msgs::msg::SpeedScalingFactor_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_msgs::msg::SpeedScalingFactor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_msgs::msg::SpeedScalingFactor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_msgs::msg::SpeedScalingFactor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_msgs__msg__SpeedScalingFactor
    std::shared_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_msgs__msg__SpeedScalingFactor
    std::shared_ptr<control_msgs::msg::SpeedScalingFactor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpeedScalingFactor_ & other) const
  {
    if (this->factor != other.factor) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpeedScalingFactor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpeedScalingFactor_

// alias to use template instance with default allocator
using SpeedScalingFactor =
  control_msgs::msg::SpeedScalingFactor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace control_msgs

#endif  // CONTROL_MSGS__MSG__DETAIL__SPEED_SCALING_FACTOR__STRUCT_HPP_
