# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Practice\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Practice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Practice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Practice.dir/flags.make

CMakeFiles/Practice.dir/main.cpp.obj: CMakeFiles/Practice.dir/flags.make
CMakeFiles/Practice.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Practice.dir/main.cpp.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Practice.dir\main.cpp.obj -c D:\Practice\main.cpp

CMakeFiles/Practice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Practice.dir/main.cpp.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Practice\main.cpp > CMakeFiles\Practice.dir\main.cpp.i

CMakeFiles/Practice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Practice.dir/main.cpp.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Practice\main.cpp -o CMakeFiles\Practice.dir\main.cpp.s

CMakeFiles/Practice.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Practice.dir/main.cpp.obj.requires

CMakeFiles/Practice.dir/main.cpp.obj.provides: CMakeFiles/Practice.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Practice.dir\build.make CMakeFiles/Practice.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Practice.dir/main.cpp.obj.provides

CMakeFiles/Practice.dir/main.cpp.obj.provides.build: CMakeFiles/Practice.dir/main.cpp.obj


# Object files for target Practice
Practice_OBJECTS = \
"CMakeFiles/Practice.dir/main.cpp.obj"

# External object files for target Practice
Practice_EXTERNAL_OBJECTS =

Practice.exe: CMakeFiles/Practice.dir/main.cpp.obj
Practice.exe: CMakeFiles/Practice.dir/build.make
Practice.exe: CMakeFiles/Practice.dir/linklibs.rsp
Practice.exe: CMakeFiles/Practice.dir/objects1.rsp
Practice.exe: CMakeFiles/Practice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Practice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Practice.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Practice.dir/build: Practice.exe

.PHONY : CMakeFiles/Practice.dir/build

CMakeFiles/Practice.dir/requires: CMakeFiles/Practice.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Practice.dir/requires

CMakeFiles/Practice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Practice.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Practice.dir/clean

CMakeFiles/Practice.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Practice D:\Practice D:\Practice\cmake-build-debug D:\Practice\cmake-build-debug D:\Practice\cmake-build-debug\CMakeFiles\Practice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Practice.dir/depend

