#pragma message("#include \"pid_controller_parameters.hpp\" is deprecated. Use #include <pid_controller/pid_controller_parameters.hpp> instead.")
// auto-generated DO NOT EDIT

#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <mutex>
#include <rclcpp/node.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <rclcpp/logger.hpp>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <parameter_traits/parameter_traits.hpp>

#include <rsl/static_string.hpp>
#include <rsl/static_vector.hpp>
#include <rsl/parameter_validators.hpp>



namespace pid_controller {

// Use validators from RSL
using rsl::unique;
using rsl::subset_of;
using rsl::fixed_size;
using rsl::size_gt;
using rsl::size_lt;
using rsl::not_empty;
using rsl::element_bounds;
using rsl::lower_element_bounds;
using rsl::upper_element_bounds;
using rsl::bounds;
using rsl::lt;
using rsl::gt;
using rsl::lt_eq;
using rsl::gt_eq;
using rsl::one_of;
using rsl::to_parameter_result_msg;

// temporarily needed for backwards compatibility for custom validators
using namespace parameter_traits;

template <typename T>
[[nodiscard]] auto to_parameter_value(T value) {
    return rclcpp::ParameterValue(value);
}

template <size_t capacity>
[[nodiscard]] auto to_parameter_value(rsl::StaticString<capacity> const& value) {
    return rclcpp::ParameterValue(rsl::to_string(value));
}

template <typename T, size_t capacity>
[[nodiscard]] auto to_parameter_value(rsl::StaticVector<T, capacity> const& value) {
    return rclcpp::ParameterValue(rsl::to_vector(value));
}
    struct Params {
        std::vector<std::string> dof_names = {};
        std::vector<std::string> reference_and_state_dof_names = {};
        std::string command_interface = "";
        std::vector<std::string> reference_and_state_interfaces = {};
        bool use_external_measured_states = false;
        struct Gains {
            struct MapDofNames {
                double p = 0.0;
                double i = 0.0;
                double d = 0.0;
                bool antiwindup = false;
                double i_clamp_max = 0.0;
                double i_clamp_min = 0.0;
                double feedforward_gain = 0.0;
                bool angle_wraparound = false;
            };
            std::map<std::string, MapDofNames> dof_names_map;
        } gains;
        // for detecting if the parameter struct has been updated
        rclcpp::Time __stamp;
    };
    struct StackParams {
        bool use_external_measured_states = false;
    };

  class ParamListener{
  public:
    // throws rclcpp::exceptions::InvalidParameterValueException on initialization if invalid parameter are loaded
    ParamListener(rclcpp::Node::SharedPtr node, std::string const& prefix = "")
    : ParamListener(node->get_node_parameters_interface(), node->get_logger(), prefix) {}

    ParamListener(rclcpp_lifecycle::LifecycleNode::SharedPtr node, std::string const& prefix = "")
    : ParamListener(node->get_node_parameters_interface(), node->get_logger(), prefix) {}

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  std::string const& prefix = "")
    : ParamListener(parameters_interface, rclcpp::get_logger("pid_controller"), prefix) {
      RCLCPP_DEBUG(logger_, "ParameterListener: Not using node logger, recommend using other constructors to use a node logger");
    }

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface>& parameters_interface,
                  rclcpp::Logger logger, std::string const& prefix = "") {
      logger_ = std::move(logger);
      prefix_ = prefix;
      if (!prefix_.empty() && prefix_.back() != '.') {
        prefix_ += ".";
      }

      parameters_interface_ = parameters_interface;
      declare_params();
      auto update_param_cb = [this](const std::vector<rclcpp::Parameter> &parameters){return this->update(parameters);};
      handle_ = parameters_interface_->add_on_set_parameters_callback(update_param_cb);
      clock_ = rclcpp::Clock();
    }

    Params get_params() const{
      std::lock_guard<std::mutex> lock(mutex_);
      return params_;
    }

    bool try_get_params(Params & params_in) const {
      if (mutex_.try_lock()) {
        if (const bool is_old = params_in.__stamp != params_.__stamp; is_old) {
          params_in = params_;
        }
        mutex_.unlock();
        return true;
      }
      return false;
    }

    bool is_old(Params const& other) const {
      std::lock_guard<std::mutex> lock(mutex_);
      return params_.__stamp != other.__stamp;
    }

    StackParams get_stack_params() {
      Params params = get_params();
      StackParams output;
      output.use_external_measured_states = params.use_external_measured_states;

      return output;
    }

    void refresh_dynamic_parameters() {
      auto updated_params = get_params();
      // TODO remove any destroyed dynamic parameters

      // declare any new dynamic parameters
      rclcpp::Parameter param;
      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "p");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Proportional gain for PID";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.p);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.p = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Integral gain for PID";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.i);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.i = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "d");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Derivative gain for PID";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.d);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.d = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "antiwindup");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Antiwindup functionality. When set to true, limits the integral error to prevent windup; otherwise, constrains the integral contribution to the control output. i_clamp_max and i_clamp_min are applied in both scenarios.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.antiwindup);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.antiwindup = param.as_bool();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i_clamp_max");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Upper integral clamp.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.i_clamp_max);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.i_clamp_max = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i_clamp_min");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Lower integral clamp.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.i_clamp_min);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.i_clamp_min = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "feedforward_gain");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Gain for the feed-forward part.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.feedforward_gain);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.feedforward_gain = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "angle_wraparound");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "For joints that wrap around (i.e., are continuous). Normalizes position-error to -pi to pi.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.angle_wraparound);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.angle_wraparound = param.as_bool();}

    }

    rcl_interfaces::msg::SetParametersResult update(const std::vector<rclcpp::Parameter> &parameters) {
      auto updated_params = get_params();

      for (const auto &param: parameters) {
        if (param.get_name() == (prefix_ + "dof_names")) {
            if(auto validation_result = unique<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            if(auto validation_result = not_empty<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.dof_names = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "reference_and_state_dof_names")) {
            if(auto validation_result = unique<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.reference_and_state_dof_names = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "command_interface")) {
            if(auto validation_result = not_empty<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.command_interface = param.as_string();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "reference_and_state_interfaces")) {
            if(auto validation_result = not_empty<std::string>(param);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            if(auto validation_result = size_lt<std::string>(param, 3);
              !validation_result) {
                return rsl::to_parameter_result_msg(validation_result);
            }
            updated_params.reference_and_state_interfaces = param.as_string_array();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
        if (param.get_name() == (prefix_ + "use_external_measured_states")) {
            updated_params.use_external_measured_states = param.as_bool();
            RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
        }
      }

      // update dynamic parameters
      for (const auto &param: parameters) {
        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "p");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].p = param.as_double();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].i = param.as_double();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "d");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].d = param.as_double();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "antiwindup");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].antiwindup = param.as_bool();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i_clamp_max");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].i_clamp_max = param.as_double();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i_clamp_min");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].i_clamp_min = param.as_double();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "feedforward_gain");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].feedforward_gain = param.as_double();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

        for (const auto & value_1 : updated_params.dof_names) {
        std::string value = fmt::format("{}", value_1);

            auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "angle_wraparound");
            if (param.get_name() == param_name) {

                updated_params.gains.dof_names_map[value_1].angle_wraparound = param.as_bool();
                RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
            }
        }

      }
      updated_params.__stamp = clock_.now();
      update_internal_params(updated_params);
      return rsl::to_parameter_result_msg({});
    }

    void declare_params(){
      auto updated_params = get_params();
      // declare all parameters and give default values to non-required ones
      if (!parameters_interface_->has_parameter(prefix_ + "dof_names")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Specifies dof_names or axes used by the controller. If 'reference_and_state_dof_names' parameter is defined, then only command dof names are defined with this parameter.";
          descriptor.read_only = true;
          auto parameter = to_parameter_value(updated_params.dof_names);
          parameters_interface_->declare_parameter(prefix_ + "dof_names", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "reference_and_state_dof_names")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "(optional) Specifies dof_names or axes for getting reference and reading states. This parameter is only relevant when state dof names are different then command dof names, i.e., when a following controller is used.";
          descriptor.read_only = true;
          auto parameter = to_parameter_value(updated_params.reference_and_state_dof_names);
          parameters_interface_->declare_parameter(prefix_ + "reference_and_state_dof_names", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "command_interface")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the interface used by the controller for writing commands to the hardware.";
          descriptor.read_only = true;
          auto parameter = to_parameter_value(updated_params.command_interface);
          parameters_interface_->declare_parameter(prefix_ + "command_interface", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "reference_and_state_interfaces")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Name of the interfaces used by the controller getting hardware states and reference commands. The second interface should be the derivative of the first.";
          descriptor.read_only = true;
          auto parameter = to_parameter_value(updated_params.reference_and_state_interfaces);
          parameters_interface_->declare_parameter(prefix_ + "reference_and_state_interfaces", parameter, descriptor);
      }
      if (!parameters_interface_->has_parameter(prefix_ + "use_external_measured_states")) {
          rcl_interfaces::msg::ParameterDescriptor descriptor;
          descriptor.description = "Use external states from a topic instead from state interfaces.";
          descriptor.read_only = false;
          auto parameter = to_parameter_value(updated_params.use_external_measured_states);
          parameters_interface_->declare_parameter(prefix_ + "use_external_measured_states", parameter, descriptor);
      }
      // get parameters and fill struct fields
      rclcpp::Parameter param;
      param = parameters_interface_->get_parameter(prefix_ + "dof_names");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = unique<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'dof_names': {}", validation_result.error()));
      }
      if(auto validation_result = not_empty<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'dof_names': {}", validation_result.error()));
      }
      updated_params.dof_names = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "reference_and_state_dof_names");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = unique<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'reference_and_state_dof_names': {}", validation_result.error()));
      }
      updated_params.reference_and_state_dof_names = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "command_interface");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = not_empty<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'command_interface': {}", validation_result.error()));
      }
      updated_params.command_interface = param.as_string();
      param = parameters_interface_->get_parameter(prefix_ + "reference_and_state_interfaces");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      if(auto validation_result = not_empty<std::string>(param);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'reference_and_state_interfaces': {}", validation_result.error()));
      }
      if(auto validation_result = size_lt<std::string>(param, 3);
        !validation_result) {
          throw rclcpp::exceptions::InvalidParameterValueException(fmt::format("Invalid value set during initialization for parameter 'reference_and_state_interfaces': {}", validation_result.error()));
      }
      updated_params.reference_and_state_interfaces = param.as_string_array();
      param = parameters_interface_->get_parameter(prefix_ + "use_external_measured_states");
      RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
      updated_params.use_external_measured_states = param.as_bool();


      // declare and set all dynamic parameters
      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "p");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Proportional gain for PID";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.p);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.p = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Integral gain for PID";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.i);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.i = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "d");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Derivative gain for PID";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.d);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.d = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "antiwindup");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Antiwindup functionality. When set to true, limits the integral error to prevent windup; otherwise, constrains the integral contribution to the control output. i_clamp_max and i_clamp_min are applied in both scenarios.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.antiwindup);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.antiwindup = param.as_bool();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i_clamp_max");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Upper integral clamp.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.i_clamp_max);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.i_clamp_max = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "i_clamp_min");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Lower integral clamp.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.i_clamp_min);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.i_clamp_min = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "feedforward_gain");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "Gain for the feed-forward part.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.feedforward_gain);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.feedforward_gain = param.as_double();}

      for (const auto & value_1 : updated_params.dof_names) {

          auto& entry = updated_params.gains.dof_names_map[value_1];
          std::string value = fmt::format("{}", value_1);

          auto param_name = fmt::format("{}{}.{}.{}", prefix_, "gains", value, "angle_wraparound");
          if (!parameters_interface_->has_parameter(param_name)) {
              rcl_interfaces::msg::ParameterDescriptor descriptor;
              descriptor.description = "For joints that wrap around (i.e., are continuous). Normalizes position-error to -pi to pi.";
              descriptor.read_only = false;
              auto parameter = rclcpp::ParameterValue(entry.angle_wraparound);
              parameters_interface_->declare_parameter(param_name, parameter, descriptor);
          }
          param = parameters_interface_->get_parameter(param_name);
          RCLCPP_DEBUG_STREAM(logger_, param.get_name() << ": " << param.get_type_name() << " = " << param.value_to_string());
          entry.angle_wraparound = param.as_bool();}


      updated_params.__stamp = clock_.now();
      update_internal_params(updated_params);
    }

    private:
      void update_internal_params(Params updated_params) {
        std::lock_guard<std::mutex> lock(mutex_);
        params_ = std::move(updated_params);
      }

      std::string prefix_;
      Params params_;
      rclcpp::Clock clock_;
      std::shared_ptr<rclcpp::node_interfaces::OnSetParametersCallbackHandle> handle_;
      std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> parameters_interface_;

      // rclcpp::Logger cannot be default-constructed
      // so we must provide a initialization here even though
      // every one of our constructors initializes logger_
      rclcpp::Logger logger_ = rclcpp::get_logger("pid_controller");
      std::mutex mutable mutex_;
  };

} // namespace pid_controller
