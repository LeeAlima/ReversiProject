# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lee/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lee/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lee/CLionProjects/ReversiProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lee/CLionProjects/ReversiProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ReversiProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReversiProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReversiProject.dir/flags.make

CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o: ../src/AIPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/AIPlayer.cpp

CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/AIPlayer.cpp > CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.i

CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/AIPlayer.cpp -o CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.s

CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o


CMakeFiles/ReversiProject.dir/src/Board.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ReversiProject.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/Board.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/Board.cpp

CMakeFiles/ReversiProject.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/Board.cpp > CMakeFiles/ReversiProject.dir/src/Board.cpp.i

CMakeFiles/ReversiProject.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/Board.cpp -o CMakeFiles/ReversiProject.dir/src/Board.cpp.s

CMakeFiles/ReversiProject.dir/src/Board.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/Board.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/Board.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/Board.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/Board.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/Board.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/Board.cpp.o


CMakeFiles/ReversiProject.dir/src/Cell.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/Cell.cpp.o: ../src/Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ReversiProject.dir/src/Cell.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/Cell.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/Cell.cpp

CMakeFiles/ReversiProject.dir/src/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/Cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/Cell.cpp > CMakeFiles/ReversiProject.dir/src/Cell.cpp.i

CMakeFiles/ReversiProject.dir/src/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/Cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/Cell.cpp -o CMakeFiles/ReversiProject.dir/src/Cell.cpp.s

CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/Cell.cpp.o


CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o: ../src/ConsoleScreen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/ConsoleScreen.cpp

CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/ConsoleScreen.cpp > CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.i

CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/ConsoleScreen.cpp -o CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.s

CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o


CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o: ../src/GameFlow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/GameFlow.cpp

CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/GameFlow.cpp > CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.i

CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/GameFlow.cpp -o CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.s

CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o


CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o: ../src/GameLogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/GameLogic.cpp

CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/GameLogic.cpp > CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.i

CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/GameLogic.cpp -o CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.s

CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o


CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o: ../src/HumanPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/HumanPlayer.cpp

CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/HumanPlayer.cpp > CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.i

CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/HumanPlayer.cpp -o CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.s

CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o


CMakeFiles/ReversiProject.dir/src/main.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ReversiProject.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/src/main.cpp.o -c /home/lee/CLionProjects/ReversiProject/src/main.cpp

CMakeFiles/ReversiProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/src/main.cpp > CMakeFiles/ReversiProject.dir/src/main.cpp.i

CMakeFiles/ReversiProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/src/main.cpp -o CMakeFiles/ReversiProject.dir/src/main.cpp.s

CMakeFiles/ReversiProject.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/src/main.cpp.o.requires

CMakeFiles/ReversiProject.dir/src/main.cpp.o.provides: CMakeFiles/ReversiProject.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/src/main.cpp.o.provides

CMakeFiles/ReversiProject.dir/src/main.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/src/main.cpp.o


CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o: ../UnitTest/gtest_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o -c /home/lee/CLionProjects/ReversiProject/UnitTest/gtest_main.cpp

CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/UnitTest/gtest_main.cpp > CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.i

CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/UnitTest/gtest_main.cpp -o CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.s

CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.requires

CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.provides: CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.provides

CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o


CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o: CMakeFiles/ReversiProject.dir/flags.make
CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o: ../UnitTest/TestFixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o -c /home/lee/CLionProjects/ReversiProject/UnitTest/TestFixture.cpp

CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lee/CLionProjects/ReversiProject/UnitTest/TestFixture.cpp > CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.i

CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lee/CLionProjects/ReversiProject/UnitTest/TestFixture.cpp -o CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.s

CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.requires:

.PHONY : CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.requires

CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.provides: CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiProject.dir/build.make CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.provides

CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.provides.build: CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o


# Object files for target ReversiProject
ReversiProject_OBJECTS = \
"CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/Board.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/Cell.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o" \
"CMakeFiles/ReversiProject.dir/src/main.cpp.o" \
"CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o" \
"CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o"

# External object files for target ReversiProject
ReversiProject_EXTERNAL_OBJECTS =

ReversiProject: CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/Board.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/Cell.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/src/main.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o
ReversiProject: CMakeFiles/ReversiProject.dir/build.make
ReversiProject: CMakeFiles/ReversiProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ReversiProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReversiProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReversiProject.dir/build: ReversiProject

.PHONY : CMakeFiles/ReversiProject.dir/build

CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/AIPlayer.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/Board.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/Cell.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/ConsoleScreen.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/GameFlow.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/GameLogic.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/HumanPlayer.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/src/main.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/UnitTest/gtest_main.cpp.o.requires
CMakeFiles/ReversiProject.dir/requires: CMakeFiles/ReversiProject.dir/UnitTest/TestFixture.cpp.o.requires

.PHONY : CMakeFiles/ReversiProject.dir/requires

CMakeFiles/ReversiProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReversiProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReversiProject.dir/clean

CMakeFiles/ReversiProject.dir/depend:
	cd /home/lee/CLionProjects/ReversiProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lee/CLionProjects/ReversiProject /home/lee/CLionProjects/ReversiProject /home/lee/CLionProjects/ReversiProject/cmake-build-debug /home/lee/CLionProjects/ReversiProject/cmake-build-debug /home/lee/CLionProjects/ReversiProject/cmake-build-debug/CMakeFiles/ReversiProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReversiProject.dir/depend

