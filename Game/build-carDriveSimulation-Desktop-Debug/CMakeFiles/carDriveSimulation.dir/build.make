# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/carDriveSimulation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/carDriveSimulation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/carDriveSimulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/carDriveSimulation.dir/flags.make

CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o: CMakeFiles/carDriveSimulation.dir/flags.make
CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o: carDriveSimulation_autogen/mocs_compilation.cpp
CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o: CMakeFiles/carDriveSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o -MF CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o -c /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/carDriveSimulation_autogen/mocs_compilation.cpp

CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/carDriveSimulation_autogen/mocs_compilation.cpp > CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.i

CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/carDriveSimulation_autogen/mocs_compilation.cpp -o CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.s

CMakeFiles/carDriveSimulation.dir/main.cpp.o: CMakeFiles/carDriveSimulation.dir/flags.make
CMakeFiles/carDriveSimulation.dir/main.cpp.o: /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/main.cpp
CMakeFiles/carDriveSimulation.dir/main.cpp.o: CMakeFiles/carDriveSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/carDriveSimulation.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/carDriveSimulation.dir/main.cpp.o -MF CMakeFiles/carDriveSimulation.dir/main.cpp.o.d -o CMakeFiles/carDriveSimulation.dir/main.cpp.o -c /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/main.cpp

CMakeFiles/carDriveSimulation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/carDriveSimulation.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/main.cpp > CMakeFiles/carDriveSimulation.dir/main.cpp.i

CMakeFiles/carDriveSimulation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/carDriveSimulation.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/main.cpp -o CMakeFiles/carDriveSimulation.dir/main.cpp.s

CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o: CMakeFiles/carDriveSimulation.dir/flags.make
CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o: /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/mainwindow.cpp
CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o: CMakeFiles/carDriveSimulation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o -MF CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o.d -o CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o -c /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/mainwindow.cpp

CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/mainwindow.cpp > CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.i

CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation/mainwindow.cpp -o CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.s

# Object files for target carDriveSimulation
carDriveSimulation_OBJECTS = \
"CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/carDriveSimulation.dir/main.cpp.o" \
"CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o"

# External object files for target carDriveSimulation
carDriveSimulation_EXTERNAL_OBJECTS =

carDriveSimulation: CMakeFiles/carDriveSimulation.dir/carDriveSimulation_autogen/mocs_compilation.cpp.o
carDriveSimulation: CMakeFiles/carDriveSimulation.dir/main.cpp.o
carDriveSimulation: CMakeFiles/carDriveSimulation.dir/mainwindow.cpp.o
carDriveSimulation: CMakeFiles/carDriveSimulation.dir/build.make
carDriveSimulation: /home/anna/Qt/6.6.2/gcc_64/lib/libQt6Widgets.so.6.6.2
carDriveSimulation: /home/anna/Qt/6.6.2/gcc_64/lib/libQt6Gui.so.6.6.2
carDriveSimulation: /home/anna/Qt/6.6.2/gcc_64/lib/libQt6Core.so.6.6.2
carDriveSimulation: /usr/lib/x86_64-linux-gnu/libGLX.so
carDriveSimulation: /usr/lib/x86_64-linux-gnu/libOpenGL.so
carDriveSimulation: CMakeFiles/carDriveSimulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable carDriveSimulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/carDriveSimulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/carDriveSimulation.dir/build: carDriveSimulation
.PHONY : CMakeFiles/carDriveSimulation.dir/build

CMakeFiles/carDriveSimulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/carDriveSimulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/carDriveSimulation.dir/clean

CMakeFiles/carDriveSimulation.dir/depend:
	cd /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation /home/anna/Desktop/Synopsys/homwork_with_David/Game/carDriveSimulation /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug /home/anna/Desktop/Synopsys/homwork_with_David/Game/build-carDriveSimulation-Desktop-Debug/CMakeFiles/carDriveSimulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/carDriveSimulation.dir/depend

