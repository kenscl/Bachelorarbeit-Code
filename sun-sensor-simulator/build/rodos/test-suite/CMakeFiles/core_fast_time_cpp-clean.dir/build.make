# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build

# Utility rule file for core_fast_time_cpp-clean.

# Include any custom commands dependencies for this target.
include rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/compiler_depend.make

# Include the progress variables for this target.
include rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/progress.make

rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && /usr/bin/cmake -E remove -f core_fast_time_cpp-bin.output core_fast_time_cpp-bin.diff

core_fast_time_cpp-clean: rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean
core_fast_time_cpp-clean: rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/build.make
.PHONY : core_fast_time_cpp-clean

# Rule to build all files generated by this target.
rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/build: core_fast_time_cpp-clean
.PHONY : rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/build

rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/clean:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && $(CMAKE_COMMAND) -P CMakeFiles/core_fast_time_cpp-clean.dir/cmake_clean.cmake
.PHONY : rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/clean

rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/depend:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : rodos/test-suite/CMakeFiles/core_fast_time_cpp-clean.dir/depend

