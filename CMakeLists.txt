cmake_minimum_required(VERSION 3.19)
project(Robotronic)

set(CMAKE_CXX_STANDARD 14)

include_directories("E:/Projects/C++/libs/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include"
        E:/Projects/C++/libs/glew-2.2.0/include E:/Projects/C++/libs/glm0999

        )

link_directories("E:/Projects/C++/libs/SDL2-devel-2.0.14-VC/SDL2-2.0.14/lib/x64"
        E:/Projects/C++/libs/glew-2.2.0/lib/Release/x64
        )

file(GLOB IMGUI_FILES ${PROJECT_SOURCE_DIR}/lib/imgui/*.*)

add_executable(Robotronic ${IMGUI_FILES} main.cpp lib/game.h game/RobotronicGame.cpp game/RobotronicGame.h lib/timer.h lib/timer.cpp lib/view.h lib/view.cpp lib/vao_factory.h lib/vao_factory.cpp lib/shader_factory.h lib/shader_factory.cpp lib/filesutils.h lib/file_utils.cpp lib/screen_context.h lib/screen_context.cpp lib/texture.cpp lib/texture.h lib/Shader.cpp lib/Shader.h)