# Install script for directory: C:/Users/Tomi/Documents/Facultad/AyED/TPs/TP_C/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/TP_C")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Tomi/Documents/Facultad/AyED/TPs/TP_C/cmake-build-debug/src/Ex1/cmake_install.cmake")
  include("C:/Users/Tomi/Documents/Facultad/AyED/TPs/TP_C/cmake-build-debug/src/Ex2/cmake_install.cmake")
  include("C:/Users/Tomi/Documents/Facultad/AyED/TPs/TP_C/cmake-build-debug/src/Ex3/cmake_install.cmake")
  include("C:/Users/Tomi/Documents/Facultad/AyED/TPs/TP_C/cmake-build-debug/src/Ex4/cmake_install.cmake")
  include("C:/Users/Tomi/Documents/Facultad/AyED/TPs/TP_C/cmake-build-debug/src/Ex5/cmake_install.cmake")

endif()

