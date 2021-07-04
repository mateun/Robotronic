#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <string>
#include "lib/game.h"
#include "game/RobotronicGame.h"
#include "lib/timer.h"
#include "lib/screen_context.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "glew32.lib")



bool shouldRun = true;


SDL_GLContext initOpenGL(SDL_Window* window) {
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GLContext ctx = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(0);  // NO VSync

    GLenum r = glewInit();
    if (r != GLEW_OK) {
        exit(1);
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    return glContext;
}

void stopGame() {
    shouldRun = false;
}



int main(int argc, char** args) {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        SDL_Log("error initializing. %s", SDL_GetError());
        return 1;
    }

    ScreenContext screenContext(800, 600);
    SDL_Window* window = SDL_CreateWindow("test 0.0.1",
                                          300, 100,
                                          screenContext.getScreenWidth(),
                                          screenContext.getScreenHeight(),
                                          SDL_WINDOW_OPENGL);
    SDL_GLContext  glContext = initOpenGL(window);


    glViewport(0, 0, 800, 600);
    Game* game = new RobotronicGame();
    Timer mainFrameTimer;

    game->init();


    std::vector<SDL_Event> frameEvents;
    while (shouldRun) {

        frameEvents.clear();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                shouldRun = false;
                game->shutdown();
                break;
            }
            frameEvents.push_back(event);
        }

        game->preRender();
        game->update(mainFrameTimer.getDurationInSeconds(), frameEvents);
        game->render(mainFrameTimer.getDurationInSeconds());

        SDL_GL_SwapWindow(window);
        mainFrameTimer.stop();

        mainFrameTimer.start();

    }


    game->shutdown();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;


}
