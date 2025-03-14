file(REMOVE_RECURSE
  "include/pid_controller/pid_controller_parameters.hpp"
  "include/pid_controller_parameters.hpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/pid_controller_parameters.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
