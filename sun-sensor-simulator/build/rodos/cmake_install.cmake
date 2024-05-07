# Install script for directory: /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/tutorials/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/src/rodos/cmake/port" TYPE DIRECTORY FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/cmake/port/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rodos/api" TYPE DIRECTORY FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/api/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rodos/src/bare-metal/linux-x86" TYPE DIRECTORY FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/src/bare-metal/linux-x86/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rodos/support/support-libs" TYPE DIRECTORY FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/support/support-libs/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rodos/src/bare-metal-generic" TYPE DIRECTORY FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/src/bare-metal-generic/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rodos" TYPE STATIC_LIBRARY FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/librodos.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake" TYPE FILE RENAME "rodosConfig.cmake" FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/cmake/install-config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake" TYPE FILE FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/rodosConfigVersion.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake/rodosTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake/rodosTargets.cmake"
         "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/CMakeFiles/Export/828070db12a45b11b477a5ffc5ebdf75/rodosTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake/rodosTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake/rodosTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake" TYPE FILE FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/CMakeFiles/Export/828070db12a45b11b477a5ffc5ebdf75/rodosTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/rodos/cmake" TYPE FILE FILES "/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/CMakeFiles/Export/828070db12a45b11b477a5ffc5ebdf75/rodosTargets-noconfig.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite/cmake_install.cmake")
endif()

