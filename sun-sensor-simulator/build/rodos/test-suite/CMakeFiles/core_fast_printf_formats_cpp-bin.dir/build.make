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

# Include any dependencies generated for this target.
include rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/compiler_depend.make

# Include the progress variables for this target.
include rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/progress.make

# Include the compile flags for this target's objects.
include rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/flags.make

rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o: rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/flags.make
rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o: /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/core-fast/printf-formats.cpp
rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o: rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o"
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o -MF CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o.d -o CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o -c /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/core-fast/printf-formats.cpp

rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.i"
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/core-fast/printf-formats.cpp > CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.i

rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.s"
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite/core-fast/printf-formats.cpp -o CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.s

# Object files for target core_fast_printf_formats_cpp-bin
core_fast_printf_formats_cpp__bin_OBJECTS = \
"CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o"

# External object files for target core_fast_printf_formats_cpp-bin
core_fast_printf_formats_cpp__bin_EXTERNAL_OBJECTS =

rodos/test-suite/core_fast_printf_formats_cpp-bin: rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/core-fast/printf-formats.cpp.o
rodos/test-suite/core_fast_printf_formats_cpp-bin: rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/build.make
rodos/test-suite/core_fast_printf_formats_cpp-bin: rodos/librodos.a
rodos/test-suite/core_fast_printf_formats_cpp-bin: rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable core_fast_printf_formats_cpp-bin"
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core_fast_printf_formats_cpp-bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/build: rodos/test-suite/core_fast_printf_formats_cpp-bin
.PHONY : rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/build

rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/clean:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite && $(CMAKE_COMMAND) -P CMakeFiles/core_fast_printf_formats_cpp-bin.dir/cmake_clean.cmake
.PHONY : rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/clean

rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/depend:
	cd /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/test-suite /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/build/rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : rodos/test-suite/CMakeFiles/core_fast_printf_formats_cpp-bin.dir/depend

