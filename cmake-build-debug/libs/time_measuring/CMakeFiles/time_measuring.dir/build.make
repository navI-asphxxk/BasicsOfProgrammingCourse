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
include libs/time_measuring/CMakeFiles/time_measuring.dir/depend.make
# Include the progress variables for this target.
include libs/time_measuring/CMakeFiles/time_measuring.dir/progress.make

# Include the compile flags for this target's objects.
include libs/time_measuring/CMakeFiles/time_measuring.dir/flags.make

libs/time_measuring/CMakeFiles/time_measuring.dir/sorts/sorts.c.obj: libs/time_measuring/CMakeFiles/time_measuring.dir/flags.make
libs/time_measuring/CMakeFiles/time_measuring.dir/sorts/sorts.c.obj: ../libs/time_measuring/sorts/sorts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/time_measuring/CMakeFiles/time_measuring.dir/sorts/sorts.c.obj"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\time_measuring.dir\sorts\sorts.c.obj -c C:\Users\maksi\CLionProjects\cource\libs\time_measuring\sorts\sorts.c

libs/time_measuring/CMakeFiles/time_measuring.dir/sorts/sorts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_measuring.dir/sorts/sorts.c.i"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maksi\CLionProjects\cource\libs\time_measuring\sorts\sorts.c > CMakeFiles\time_measuring.dir\sorts\sorts.c.i

libs/time_measuring/CMakeFiles/time_measuring.dir/sorts/sorts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_measuring.dir/sorts/sorts.c.s"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maksi\CLionProjects\cource\libs\time_measuring\sorts\sorts.c -o CMakeFiles\time_measuring.dir\sorts\sorts.c.s

libs/time_measuring/CMakeFiles/time_measuring.dir/main.c.obj: libs/time_measuring/CMakeFiles/time_measuring.dir/flags.make
libs/time_measuring/CMakeFiles/time_measuring.dir/main.c.obj: ../libs/time_measuring/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/time_measuring/CMakeFiles/time_measuring.dir/main.c.obj"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\time_measuring.dir\main.c.obj -c C:\Users\maksi\CLionProjects\cource\libs\time_measuring\main.c

libs/time_measuring/CMakeFiles/time_measuring.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_measuring.dir/main.c.i"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maksi\CLionProjects\cource\libs\time_measuring\main.c > CMakeFiles\time_measuring.dir\main.c.i

libs/time_measuring/CMakeFiles/time_measuring.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_measuring.dir/main.c.s"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maksi\CLionProjects\cource\libs\time_measuring\main.c -o CMakeFiles\time_measuring.dir\main.c.s

libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.obj: libs/time_measuring/CMakeFiles/time_measuring.dir/flags.make
libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.obj: ../libs/algorithms/array/array.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.obj"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\time_measuring.dir\__\algorithms\array\array.c.obj -c C:\Users\maksi\CLionProjects\cource\libs\algorithms\array\array.c

libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.i"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maksi\CLionProjects\cource\libs\algorithms\array\array.c > CMakeFiles\time_measuring.dir\__\algorithms\array\array.c.i

libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.s"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maksi\CLionProjects\cource\libs\algorithms\array\array.c -o CMakeFiles\time_measuring.dir\__\algorithms\array\array.c.s

libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.obj: libs/time_measuring/CMakeFiles/time_measuring.dir/flags.make
libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.obj: ../libs/algorithms/algorithm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.obj"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\time_measuring.dir\__\algorithms\algorithm.c.obj -c C:\Users\maksi\CLionProjects\cource\libs\algorithms\algorithm.c

libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.i"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maksi\CLionProjects\cource\libs\algorithms\algorithm.c > CMakeFiles\time_measuring.dir\__\algorithms\algorithm.c.i

libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.s"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maksi\CLionProjects\cource\libs\algorithms\algorithm.c -o CMakeFiles\time_measuring.dir\__\algorithms\algorithm.c.s

# Object files for target time_measuring
time_measuring_OBJECTS = \
"CMakeFiles/time_measuring.dir/sorts/sorts.c.obj" \
"CMakeFiles/time_measuring.dir/main.c.obj" \
"CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.obj" \
"CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.obj"

# External object files for target time_measuring
time_measuring_EXTERNAL_OBJECTS =

libs/time_measuring/libtime_measuring.a: libs/time_measuring/CMakeFiles/time_measuring.dir/sorts/sorts.c.obj
libs/time_measuring/libtime_measuring.a: libs/time_measuring/CMakeFiles/time_measuring.dir/main.c.obj
libs/time_measuring/libtime_measuring.a: libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/array/array.c.obj
libs/time_measuring/libtime_measuring.a: libs/time_measuring/CMakeFiles/time_measuring.dir/__/algorithms/algorithm.c.obj
libs/time_measuring/libtime_measuring.a: libs/time_measuring/CMakeFiles/time_measuring.dir/build.make
libs/time_measuring/libtime_measuring.a: libs/time_measuring/CMakeFiles/time_measuring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\maksi\CLionProjects\cource\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libtime_measuring.a"
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && $(CMAKE_COMMAND) -P CMakeFiles\time_measuring.dir\cmake_clean_target.cmake
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\time_measuring.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/time_measuring/CMakeFiles/time_measuring.dir/build: libs/time_measuring/libtime_measuring.a
.PHONY : libs/time_measuring/CMakeFiles/time_measuring.dir/build

libs/time_measuring/CMakeFiles/time_measuring.dir/clean:
	cd /d C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring && $(CMAKE_COMMAND) -P CMakeFiles\time_measuring.dir\cmake_clean.cmake
.PHONY : libs/time_measuring/CMakeFiles/time_measuring.dir/clean

libs/time_measuring/CMakeFiles/time_measuring.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\maksi\CLionProjects\cource C:\Users\maksi\CLionProjects\cource\libs\time_measuring C:\Users\maksi\CLionProjects\cource\cmake-build-debug C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring C:\Users\maksi\CLionProjects\cource\cmake-build-debug\libs\time_measuring\CMakeFiles\time_measuring.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/time_measuring/CMakeFiles/time_measuring.dir/depend

