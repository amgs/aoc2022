# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/amgs/dev/aoc2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amgs/dev/aoc2022/build

# Include any dependencies generated for this target.
include CMakeFiles/d1p1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/d1p1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/d1p1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/d1p1.dir/flags.make

CMakeFiles/d1p1.dir/day1/part1.c.o: CMakeFiles/d1p1.dir/flags.make
CMakeFiles/d1p1.dir/day1/part1.c.o: ../day1/part1.c
CMakeFiles/d1p1.dir/day1/part1.c.o: CMakeFiles/d1p1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amgs/dev/aoc2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/d1p1.dir/day1/part1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/d1p1.dir/day1/part1.c.o -MF CMakeFiles/d1p1.dir/day1/part1.c.o.d -o CMakeFiles/d1p1.dir/day1/part1.c.o -c /home/amgs/dev/aoc2022/day1/part1.c

CMakeFiles/d1p1.dir/day1/part1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/d1p1.dir/day1/part1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/amgs/dev/aoc2022/day1/part1.c > CMakeFiles/d1p1.dir/day1/part1.c.i

CMakeFiles/d1p1.dir/day1/part1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/d1p1.dir/day1/part1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/amgs/dev/aoc2022/day1/part1.c -o CMakeFiles/d1p1.dir/day1/part1.c.s

# Object files for target d1p1
d1p1_OBJECTS = \
"CMakeFiles/d1p1.dir/day1/part1.c.o"

# External object files for target d1p1
d1p1_EXTERNAL_OBJECTS =

d1p1: CMakeFiles/d1p1.dir/day1/part1.c.o
d1p1: CMakeFiles/d1p1.dir/build.make
d1p1: CMakeFiles/d1p1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amgs/dev/aoc2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable d1p1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/d1p1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/d1p1.dir/build: d1p1
.PHONY : CMakeFiles/d1p1.dir/build

CMakeFiles/d1p1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/d1p1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/d1p1.dir/clean

CMakeFiles/d1p1.dir/depend:
	cd /home/amgs/dev/aoc2022/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amgs/dev/aoc2022 /home/amgs/dev/aoc2022 /home/amgs/dev/aoc2022/build /home/amgs/dev/aoc2022/build /home/amgs/dev/aoc2022/build/CMakeFiles/d1p1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/d1p1.dir/depend

