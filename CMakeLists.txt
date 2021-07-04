cmake_minimum_required(VERSION 3.19)
project(Robotronic)

set(CMAKE_CXX_STANDARD 14)

include_directories("E:/Projects/C++/libs/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include"
        E:/Projects/C++/libs/glew-2.2.0/include        


        )
link_directories("E:/Projects/C++/libs/SDL2-devel-2.0.14-VC/SDL2-2.0.14/lib/x64",
        E:/Projects/C++/libs/glew-2.2.0/lib/Release/x64
        )

add_executable(Robotronic main.cpp lib/game.h game/RobotronicGame.cpp game/RobotronicGame.h lib/timer.h lib/timer.cpp)