# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\maksi\CLionProjects\cource

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\maksi\CLionProjects\cource\cmake-build-debug

# Include any dependencies generated for this target.
include libs/data_structures/CMakeFiles/str.dir/depend.make
# Include the progress variables for this target.
include libs/data_structures/CMakeFiles/str.dir/progress.make

# Include the compile flags for this target's objects.
include libs/data_structures/CMakeFiles/str.dir/flags.make

libs/data_structures/CMakeFiles/str.dir/string/string_.c.obj: libs/data_structures/CMakeFiles/str.dir/flags.make
libs/data_structures/CMakeFiles/str.dir/string/string_.c.obj: ../libs/data_structures/string/string_.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/data_structures/CMakeFiles/str.dir/string/string_.c.obj"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\str.dir\string\string_.c.obj -c C:\Users\maksi\CLionProjects\cource\libs\data_structures\string\string_.c

libs/data_structures/CMakeFiles/str.dir/string/string_.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/str.dir/string/string_.c.i"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maksi\CLionProjects\cource\libs\data_structures\string\string_.c > CMakeFiles\str.dir\string\string_.c.i

libs/data_structures/CMakeFiles/str.dir/string/string_.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/str.dir/string/string_.c.s"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maksi\CLionProjects\cource\libs\data_structures\string\string_.c -o CMakeFiles\str.dir\string\string_.c.s

# Object files for target str
str_OBJECTS = \
"CMakeFiles/str.dir/string/string_.c.obj"

# External object files for target str
str_EXTERNAL_OBJECTS =

libs/data_structures/libstr.a: libs/data_structures/CMakeFiles/str.dir/string/string_.c.obj
libs/data_structures/libstr.a: libs/data_structures/CMakeFiles/str.dir/build.make
libs/data_structures/libstr.a: libs/data_structures/CMakeFiles/str.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libstr.a"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures && $(CMAKE_COMMAND) -P CMakeFiles\str.dir\cmake_clean_target.cmake
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\str.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/data_structures/CMakeFiles/str.dir/build: libs/data_structures/libstr.a
.PHONY : libs/data_structures/CMakeFiles/str.dir/build

libs/data_structures/CMakeFiles/str.dir/clean:
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures && $(CMAKE_COMMAND) -P CMakeFiles\str.dir\cmake_clean.cmake
.PHONY : libs/data_structures/CMakeFiles/str.dir/clean

libs/data_structures/CMakeFiles/str.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\maksi\CLionProjects\cource C:\Users\maksi\CLionProjects\cource\libs\data_structures C:\Users\maksi\CLionProjects\cource\cmake-build-debug C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\data_structures\CMakeFiles\str.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/data_structures/CMakeFiles/str.dir/depend
