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

# Utility rule file for middleware_tests_filter_cpp-run.

# Include any custom commands dependencies for this target.
include rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/compiler_depend.make

# Include the progress variables for this target.
include rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/progress.make

rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run: rodos/test-suite/middleware_tests_filter_cpp-bin.diff

rodos/test-suite/middleware_tests_filter_cpp-bin.output: rodos/test-suite/middleware_tests_filter_cpp-bin
rodos/test-suite/middleware_tests_filter_cpp-bin.output: /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/test-runner.sh
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating middleware_tests_filter_cpp-bin.output, middleware_tests_filter_cpp-bin.diff"
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && bash /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/test-runner.sh /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite/middleware_tests_filter_cpp-bin /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/expected-outputs/filter.txt

rodos/test-suite/middleware_tests_filter_cpp-bin.diff: rodos/test-suite/middleware_tests_filter_cpp-bin.output
	@$(CMAKE_COMMAND) -E touch_nocreate rodos/test-suite/middleware_tests_filter_cpp-bin.diff

middleware_tests_filter_cpp-run: rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run
middleware_tests_filter_cpp-run: rodos/test-suite/middleware_tests_filter_cpp-bin.diff
middleware_tests_filter_cpp-run: rodos/test-suite/middleware_tests_filter_cpp-bin.output
middleware_tests_filter_cpp-run: rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/build.make
.PHONY : middleware_tests_filter_cpp-run

# Rule to build all files generated by this target.
rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/build: middleware_tests_filter_cpp-run
.PHONY : rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/build

rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/clean:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && $(CMAKE_COMMAND) -P CMakeFiles/middleware_tests_filter_cpp-run.dir/cmake_clean.cmake
.PHONY : rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/clean

rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/depend:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : rodos/test-suite/CMakeFiles/middleware_tests_filter_cpp-run.dir/depend

