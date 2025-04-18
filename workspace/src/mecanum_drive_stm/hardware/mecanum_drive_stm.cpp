// Copyright 2021 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mecanum_drive_stm/mecanum_drive_stm.hpp"

#include <chrono>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

#include "hardware_interface/lexical_casts.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "rclcpp/rclcpp.hpp"

namespace mecanum_drive_stm
{
hardware_interface::CallbackReturn MecanumDriveSTMHardware::on_init(
  const hardware_interface::HardwareInfo & info)
{
  if (
    hardware_interface::SystemInterface::on_init(info) !=
    hardware_interface::CallbackReturn::SUCCESS)
  {
    return hardware_interface::CallbackReturn::ERROR;
  }


  cfg_.front_left_wheel_name = info_.hardware_parameters["front_left_wheel_name"];
  cfg_.front_right_wheel_name = info_.hardware_parameters["front_right_wheel_name"];
  cfg_.back_left_wheel_name = info_.hardware_parameters["back_left_wheel_name"];
  cfg_.back_right_wheel_name = info_.hardware_parameters["back_right_wheel_name"];
  cfg_.loop_rate = std::stof(info_.hardware_parameters["loop_rate"]);
  cfg_.device = info_.hardware_parameters["device"];
  cfg_.baud_rate = std::stoi(info_.hardware_parameters["baud_rate"]);
  cfg_.timeout_ms = std::stoi(info_.hardware_parameters["timeout_ms"]); 
  cfg_.f_enc_counts_per_rev = std::stoi(info_.hardware_parameters["front_enc_counts_per_rev"]);   
  cfg_.b_enc_counts_per_rev = std::stoi(info_.hardware_parameters["back_enc_counts_per_rev"]);   
  
  wheel_fl_.setup(cfg_.front_left_wheel_name, cfg_.f_enc_counts_per_rev);
  wheel_fr_.setup(cfg_.front_right_wheel_name, cfg_.f_enc_counts_per_rev);
  wheel_bl_.setup(cfg_.back_left_wheel_name, cfg_.b_enc_counts_per_rev);
  wheel_br_.setup(cfg_.back_right_wheel_name, cfg_.b_enc_counts_per_rev);

  for (const hardware_interface::ComponentInfo & joint : info_.joints)
  {
    // DiffBotSystem has exactly two states and one command interface on each joint
    if (joint.command_interfaces.size() != 1)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("MecanumDriveSTMHardware"), "Joint '%s' has %zu command interfaces found. 1 expected.",
        joint.name.c_str(), joint.command_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.command_interfaces[0].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("MecanumDriveSTMHardware"), "Joint '%s' have %s command interfaces found. '%s' expected.",
        joint.name.c_str(), joint.command_interfaces[0].name.c_str(),
        hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces.size() != 1)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("MecanumDriveSTMHardware"), "Joint '%s' has %zu state interface. 1 expected.", joint.name.c_str(),
        joint.state_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }


    if (joint.state_interfaces[0].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("MecanumDriveSTMHardware"), "Joint '%s' have '%s' as state interface. '%s' expected.",
        joint.name.c_str(), joint.state_interfaces[1].name.c_str(),
        hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }
  }

  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> MecanumDriveSTMHardware::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;

  state_interfaces.emplace_back(wheel_fl_.name, hardware_interface::HW_IF_VELOCITY, &wheel_fl_.vel);
  state_interfaces.emplace_back(wheel_fl_.name, hardware_interface::HW_IF_POSITION, &wheel_fl_.pos);

  state_interfaces.emplace_back(wheel_fr_.name, hardware_interface::HW_IF_VELOCITY, &wheel_fr_.vel);
  state_interfaces.emplace_back(wheel_fr_.name, hardware_interface::HW_IF_POSITION, &wheel_fr_.pos);

  state_interfaces.emplace_back(wheel_bl_.name, hardware_interface::HW_IF_VELOCITY, &wheel_bl_.vel);
  state_interfaces.emplace_back(wheel_bl_.name, hardware_interface::HW_IF_POSITION, &wheel_bl_.pos);

  state_interfaces.emplace_back(wheel_br_.name, hardware_interface::HW_IF_VELOCITY, &wheel_br_.vel);
  state_interfaces.emplace_back(wheel_br_.name, hardware_interface::HW_IF_POSITION, &wheel_br_.pos);

  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> MecanumDriveSTMHardware::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;

  command_interfaces.emplace_back(wheel_fl_.name, hardware_interface::HW_IF_VELOCITY, &wheel_fl_.cmd);

  command_interfaces.emplace_back(wheel_fr_.name, hardware_interface::HW_IF_VELOCITY, &wheel_fr_.cmd);

  command_interfaces.emplace_back(wheel_bl_.name, hardware_interface::HW_IF_VELOCITY, &wheel_bl_.cmd);

  command_interfaces.emplace_back(wheel_br_.name, hardware_interface::HW_IF_VELOCITY, &wheel_br_.cmd);
  return command_interfaces;
}

hardware_interface::CallbackReturn MecanumDriveSTMHardware::on_configure(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Configuring ...please wait...");
  comms_.connect(cfg_.device, cfg_.baud_rate, cfg_.timeout_ms);
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Successfully configured!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MecanumDriveSTMHardware::on_cleanup(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Cleaning up ...please wait...");
  comms_.disconnect();
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Successfully cleaned up!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MecanumDriveSTMHardware::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Activating ...please wait...");
  comms_.buzz(100);
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Successfully activated!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn MecanumDriveSTMHardware::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Deactivating ...please wait...");
  comms_.buzz(300);
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "Successfully deactivated!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::return_type MecanumDriveSTMHardware::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & period)
{
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "reading");

  comms_.read_encoder_values(wheel_fl_.enc, wheel_fr_.enc, wheel_bl_.enc, wheel_br_.enc);

  double delta_seconds = period.seconds();
  double pos_prev = wheel_fl_.pos;
  wheel_fl_.pos = wheel_fl_.calc_enc_angle();
  wheel_fl_.vel = (wheel_fl_.pos - pos_prev) / delta_seconds;

  pos_prev = wheel_fr_.pos;
  wheel_fr_.pos = wheel_fr_.calc_enc_angle();
  wheel_fr_.vel = (wheel_fr_.pos - pos_prev) / delta_seconds;

  pos_prev = wheel_bl_.pos;
  wheel_bl_.pos = wheel_bl_.calc_enc_angle();
  wheel_bl_.vel = (wheel_bl_.pos - pos_prev) / delta_seconds;


  pos_prev = wheel_br_.pos;
  wheel_br_.pos = wheel_br_.calc_enc_angle();
  wheel_br_.vel = (wheel_br_.pos - pos_prev) / delta_seconds;


  return hardware_interface::return_type::OK;
}

hardware_interface::return_type mecanum_drive_stm ::MecanumDriveSTMHardware::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  RCLCPP_INFO(rclcpp::get_logger("MecanumDriveSTMHardware"), "writing");

  int wheel_fl_rpm = (wheel_fl_.cmd / (2*M_PI)) / 60;
  int wheel_fr_rpm = (wheel_fr_.cmd / (2*M_PI)) / 60;
  int wheel_bl_rpm = (wheel_bl_.cmd / (2*M_PI)) / 60;
  int wheel_br_rpm = (wheel_br_.cmd / (2*M_PI)) / 60;

  comms_.set_motor_values(wheel_fl_rpm, wheel_fr_rpm, wheel_bl_rpm, wheel_br_rpm);

  return hardware_interface::return_type::OK;
}

}  // namespace mecanum_drive_stm

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(
  mecanum_drive_stm::MecanumDriveSTMHardware, hardware_interface::SystemInterface)
