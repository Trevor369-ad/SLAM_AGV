// Copyright 2015 Open Source Robotics Foundation, Inc.
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

#ifndef HARDWARE_INTERFACE__VERSION_H_
#define HARDWARE_INTERFACE__VERSION_H_

/// \def HARDWARE_INTERFACE_VERSION_MAJOR
/// Defines HARDWARE_INTERFACE major version number
#define HARDWARE_INTERFACE_VERSION_MAJOR (2)

/// \def HARDWARE_INTERFACE_VERSION_MINOR
/// Defines HARDWARE_INTERFACE minor version number
#define HARDWARE_INTERFACE_VERSION_MINOR (48)

/// \def HARDWARE_INTERFACE_VERSION_PATCH
/// Defines HARDWARE_INTERFACE version patch number
#define HARDWARE_INTERFACE_VERSION_PATCH (0)

/// \def HARDWARE_INTERFACE_VERSION_STR
/// Defines HARDWARE_INTERFACE version string
#define HARDWARE_INTERFACE_VERSION_STR "2.48.0"

/// \def HARDWARE_INTERFACE_VERSION_GTE
/// Defines a macro to check whether the version of HARDWARE_INTERFACE is greater than or equal to
/// the given version triple.
#define HARDWARE_INTERFACE_VERSION_GTE(major, minor, patch) ( \
     (major < HARDWARE_INTERFACE_VERSION_MAJOR) ? true \
     : (major > HARDWARE_INTERFACE_VERSION_MAJOR) ? false \
     : (minor < HARDWARE_INTERFACE_VERSION_MINOR) ? true \
     : (minor > HARDWARE_INTERFACE_VERSION_MINOR) ? false \
     : (patch < HARDWARE_INTERFACE_VERSION_PATCH) ? true \
     : (patch > HARDWARE_INTERFACE_VERSION_PATCH) ? false \
     : true)

#endif  // HARDWARE_INTERFACE__VERSION_H_
