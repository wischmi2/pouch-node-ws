# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Brian/pouch-node-ws/pouch/examples/ble_gatt")
  file(MAKE_DIRECTORY "C:/Users/Brian/pouch-node-ws/pouch/examples/ble_gatt")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Brian/pouch-node-ws/build/ble_gatt"
  "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix"
  "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix/tmp"
  "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix/src/ble_gatt-stamp"
  "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix/src"
  "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix/src/ble_gatt-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix/src/ble_gatt-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Brian/pouch-node-ws/build/_sysbuild/sysbuild/images/ble_gatt-prefix/src/ble_gatt-stamp${cfgdir}") # cfgdir has leading slash
endif()
