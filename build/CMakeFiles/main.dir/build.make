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
CMAKE_COMMAND = "D:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "D:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/source/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/source/main.cpp.obj: C:/Users/17894/Desktop/Curriculum/Fundamental\ of\ Computational\ Fluid\ Dynamics/Quasi-One-Dimensional\ DeLaval\ Nozzle/source/main.cpp
CMakeFiles/main.dir/source/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/source/main.cpp.obj"
	"D:/Program Files/mingw64/bin/g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/source/main.cpp.obj -MF CMakeFiles/main.dir/source/main.cpp.obj.d -o CMakeFiles/main.dir/source/main.cpp.obj -c "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/source/main.cpp"

CMakeFiles/main.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/source/main.cpp.i"
	"D:/Program Files/mingw64/bin/g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/source/main.cpp" > CMakeFiles/main.dir/source/main.cpp.i

CMakeFiles/main.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/source/main.cpp.s"
	"D:/Program Files/mingw64/bin/g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/source/main.cpp" -o CMakeFiles/main.dir/source/main.cpp.s

CMakeFiles/main.dir/source/initialize.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/source/initialize.cpp.obj: C:/Users/17894/Desktop/Curriculum/Fundamental\ of\ Computational\ Fluid\ Dynamics/Quasi-One-Dimensional\ DeLaval\ Nozzle/source/initialize.cpp
CMakeFiles/main.dir/source/initialize.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/source/initialize.cpp.obj"
	"D:/Program Files/mingw64/bin/g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/source/initialize.cpp.obj -MF CMakeFiles/main.dir/source/initialize.cpp.obj.d -o CMakeFiles/main.dir/source/initialize.cpp.obj -c "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/source/initialize.cpp"

CMakeFiles/main.dir/source/initialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/source/initialize.cpp.i"
	"D:/Program Files/mingw64/bin/g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/source/initialize.cpp" > CMakeFiles/main.dir/source/initialize.cpp.i

CMakeFiles/main.dir/source/initialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/source/initialize.cpp.s"
	"D:/Program Files/mingw64/bin/g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/source/initialize.cpp" -o CMakeFiles/main.dir/source/initialize.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/source/main.cpp.obj" \
"CMakeFiles/main.dir/source/initialize.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/source/main.cpp.obj
main.exe: CMakeFiles/main.dir/source/initialize.cpp.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: CMakeFiles/main.dir/linkLibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable main.exe"
	"D:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/main.dir/objects.a
	"D:/Program Files/mingw64/bin/ar.exe" qc CMakeFiles/main.dir/objects.a @CMakeFiles/main.dir/objects1.rsp
	"D:/Program Files/mingw64/bin/g++.exe" -g -Wl,--whole-archive CMakeFiles/main.dir/objects.a -Wl,--no-whole-archive -o main.exe -Wl,--out-implib,libmain.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/main.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle" "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle" "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build" "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build" "C:/Users/17894/Desktop/Curriculum/Fundamental of Computational Fluid Dynamics/Quasi-One-Dimensional DeLaval Nozzle/build/CMakeFiles/main.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

