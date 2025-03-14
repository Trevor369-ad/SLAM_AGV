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

#ifndef JOINT_LIMITS__VERSION_H_
#define JOINT_LIMITS__VERSION_H_

/// \def JOINT_LIMITS_VERSION_MAJOR
/// Defines JOINT_LIMITS major version number
#define JOINT_LIMITS_VERSION_MAJOR (2)

/// \def JOINT_LIMITS_VERSION_MINOR
/// Defines JOINT_LIMITS minor version number
#define JOINT_LIMITS_VERSION_MINOR (48)

/// \def JOINT_LIMITS_VERSION_PATCH
/// Defines JOINT_LIMITS version patch number
#define JOINT_LIMITS_VERSION_PATCH (0)

/// \def JOINT_LIMITS_VERSION_STR
/// Defines JOINT_LIMITS version string
#define JOINT_LIMITS_VERSION_STR "2.48.0"

/// \def JOINT_LIMITS_VERSION_GTE
/// Defines a macro to check whether the version of JOINT_LIMITS is greater than or equal to
/// the given version triple.
#define JOINT_LIMITS_VERSION_GTE(major, minor, patch) ( \
     (major < JOINT_LIMITS_VERSION_MAJOR) ? true \
     : (major > JOINT_LIMITS_VERSION_MAJOR) ? false \
     : (minor < JOINT_LIMITS_VERSION_MINOR) ? true \
     : (minor > JOINT_LIMITS_VERSION_MINOR) ? false \
     : (patch < JOINT_LIMITS_VERSION_PATCH) ? true \
     : (patch > JOINT_LIMITS_VERSION_PATCH) ? false \
     : true)

#endif  // JOINT_LIMITS__VERSION_H_
