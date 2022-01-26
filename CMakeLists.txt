cmake_minimum_required(VERSION 3.19)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp Target.cpp Target.h sqlite3 Button.cpp Button.h LevelMenu.cpp LevelMenu.h common.h Game.cpp Game.h TextInput.cpp TextInput.h ResultsScreen.cpp ResultsScreen.h DatabaseService.cpp DatabaseService.h cmake-build-debug/Table.cpp cmake-build-debug/Table.h Row.cpp Row.h RankScreen.cpp RankScreen.h Application.cpp Application.h)

