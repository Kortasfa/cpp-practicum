# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = C:\Users\student.METATECH\Downloads\CppDistro\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\student.METATECH\Downloads\CppDistro\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\student.METATECH\Documents\Timofeev\sfml.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\student.METATECH\Documents\Timofeev\sfml.1

# Include any dependencies generated for this target.
include 01/CMakeFiles/01.dir/depend.make

# Include the progress variables for this target.
include 01/CMakeFiles/01.dir/progress.make

# Include the compile flags for this target's objects.
include 01/CMakeFiles/01.dir/flags.make

01/CMakeFiles/01.dir/main.cpp.obj: 01/CMakeFiles/01.dir/flags.make
01/CMakeFiles/01.dir/main.cpp.obj: 01/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\student.METATECH\Documents\Timofeev\sfml.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 01/CMakeFiles/01.dir/main.cpp.obj"
	cd /d C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 && C:\Users\student.METATECH\Downloads\CppDistro\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\01.dir\main.cpp.obj -c C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01\main.cpp

01/CMakeFiles/01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01.dir/main.cpp.i"
	cd /d C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 && C:\Users\student.METATECH\Downloads\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01\main.cpp > CMakeFiles\01.dir\main.cpp.i

01/CMakeFiles/01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01.dir/main.cpp.s"
	cd /d C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 && C:\Users\student.METATECH\Downloads\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01\main.cpp -o CMakeFiles\01.dir\main.cpp.s

01/CMakeFiles/01.dir/main.cpp.obj.requires:

.PHONY : 01/CMakeFiles/01.dir/main.cpp.obj.requires

01/CMakeFiles/01.dir/main.cpp.obj.provides: 01/CMakeFiles/01.dir/main.cpp.obj.requires
	$(MAKE) -f 01\CMakeFiles\01.dir\build.make 01/CMakeFiles/01.dir/main.cpp.obj.provides.build
.PHONY : 01/CMakeFiles/01.dir/main.cpp.obj.provides

01/CMakeFiles/01.dir/main.cpp.obj.provides.build: 01/CMakeFiles/01.dir/main.cpp.obj


# Object files for target 01
01_OBJECTS = \
"CMakeFiles/01.dir/main.cpp.obj"

# External object files for target 01
01_EXTERNAL_OBJECTS =

01/01.exe: 01/CMakeFiles/01.dir/main.cpp.obj
01/01.exe: 01/CMakeFiles/01.dir/build.make
01/01.exe: C:/Users/student.METATECH/Downloads/CppDistro/MinGW/lib/libsfml-window-s.a
01/01.exe: C:/Users/student.METATECH/Downloads/CppDistro/MinGW/lib/libsfml-graphics-s.a
01/01.exe: C:/Users/student.METATECH/Downloads/CppDistro/MinGW/lib/libsfml-system-s.a
01/01.exe: C:/Users/student.METATECH/Downloads/CppDistro/MinGW/lib/libfreetype.a
01/01.exe: C:/Users/student.METATECH/Downloads/CppDistro/MinGW/lib/libjpeg.a
01/01.exe: 01/CMakeFiles/01.dir/linklibs.rsp
01/01.exe: 01/CMakeFiles/01.dir/objects1.rsp
01/01.exe: 01/CMakeFiles/01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\student.METATECH\Documents\Timofeev\sfml.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 01.exe"
	cd /d C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\01.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
01/CMakeFiles/01.dir/build: 01/01.exe

.PHONY : 01/CMakeFiles/01.dir/build

01/CMakeFiles/01.dir/requires: 01/CMakeFiles/01.dir/main.cpp.obj.requires

.PHONY : 01/CMakeFiles/01.dir/requires

01/CMakeFiles/01.dir/clean:
	cd /d C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 && $(CMAKE_COMMAND) -P CMakeFiles\01.dir\cmake_clean.cmake
.PHONY : 01/CMakeFiles/01.dir/clean

01/CMakeFiles/01.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\student.METATECH\Documents\Timofeev\sfml.1 C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 C:\Users\student.METATECH\Documents\Timofeev\sfml.1 C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01 C:\Users\student.METATECH\Documents\Timofeev\sfml.1\01\CMakeFiles\01.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 01/CMakeFiles/01.dir/depend

