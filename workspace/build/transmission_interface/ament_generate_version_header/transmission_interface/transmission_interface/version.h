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

#ifndef TRANSMISSION_INTERFACE__VERSION_H_
#define TRANSMISSION_INTERFACE__VERSION_H_

/// \def TRANSMISSION_INTERFACE_VERSION_MAJOR
/// Defines TRANSMISSION_INTERFACE major version number
#define TRANSMISSION_INTERFACE_VERSION_MAJOR (2)

/// \def TRANSMISSION_INTERFACE_VERSION_MINOR
/// Defines TRANSMISSION_INTERFACE minor version number
#define TRANSMISSION_INTERFACE_VERSION_MINOR (48)

/// \def TRANSMISSION_INTERFACE_VERSION_PATCH
/// Defines TRANSMISSION_INTERFACE version patch number
#define TRANSMISSION_INTERFACE_VERSION_PATCH (0)

/// \def TRANSMISSION_INTERFACE_VERSION_STR
/// Defines TRANSMISSION_INTERFACE version string
#define TRANSMISSION_INTERFACE_VERSION_STR "2.48.0"

/// \def TRANSMISSION_INTERFACE_VERSION_GTE
/// Defines a macro to check whether the version of TRANSMISSION_INTERFACE is greater than or equal to
/// the given version triple.
#define TRANSMISSION_INTERFACE_VERSION_GTE(major, minor, patch) ( \
     (major < TRANSMISSION_INTERFACE_VERSION_MAJOR) ? true \
     : (major > TRANSMISSION_INTERFACE_VERSION_MAJOR) ? false \
     : (minor < TRANSMISSION_INTERFACE_VERSION_MINOR) ? true \
     : (minor > TRANSMISSION_INTERFACE_VERSION_MINOR) ? false \
     : (patch < TRANSMISSION_INTERFACE_VERSION_PATCH) ? true \
     : (patch > TRANSMISSION_INTERFACE_VERSION_PATCH) ? false \
     : true)

#endif  // TRANSMISSION_INTERFACE__VERSION_H_
