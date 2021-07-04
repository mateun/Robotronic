#include <SDL.h>
#include <GL/glew.h>
#include <vector>
#include <string>
#include "lib/game.h"
#include "game/RobotronicGame.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "glew32.lib")


GLuint vao;
GLuint shader;

#define GLERR \
    GLenum err = glGetError(); \
    if (err != 0) { \
        SDL_Log("gl error %d\n", err); \
    } \

std::string f_read_file(const std::string& fileName)
{
    std::string result = "";
    FILE* f;
    fopen_s(&f, fileName.c_str(), "rb");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    rewind(f);

    char* buf = new char[size+1];
    memset(buf, 0, sizeof(buf));
    int read = fread_s(buf, size, 1, size, f);
    if (read != size) {
        SDL_Log("error reading file\n.");
        exit(1);
    }
    buf[size] = '\0';

    result = buf;
    fclose(f);
    return result;

}


GLuint f_createShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vssource_char = vertexShaderSource.c_str();
    glShaderSource(vshader, 1, &vssource_char, NULL);
    glCompileShader(vshader);
    GLint compileStatus;
    glGetShaderiv(vshader, GL_COMPILE_STATUS, &compileStatus);
    if (GL_FALSE == compileStatus) {

        GLint logSize = 0;
        glGetShaderiv(vshader, GL_INFO_LOG_LENGTH, &logSize);
        std::vector<GLchar> errorLog(logSize);
        glGetShaderInfoLog(vshader, logSize, &logSize, &errorLog[0]);
    //    result.errorMessage = errorLog.data();
        glDeleteShader(vshader);
      //  return result;
      return 0;

    }


    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fssource_char = fragmentShaderSource.c_str();
    glShaderSource(fshader, 1, &fssource_char, NULL);
    glCompileShader(fshader);

    glGetShaderiv(fshader, GL_COMPILE_STATUS, &compileStatus);
    if (GL_FALSE == compileStatus) {
        GLint logSize = 0;
        glGetShaderiv(fshader, GL_INFO_LOG_LENGTH, &logSize);
        std::vector<GLchar> errorLog(logSize);
        glGetShaderInfoLog(fshader, logSize, &logSize, &errorLog[0]);
     //   result.errorMessage = errorLog.data();
        glDeleteShader(fshader);
        return 0;

    }

    GLuint p = glCreateProgram();
    glAttachShader(p, vshader);
    glAttachShader(p, fshader);
    glLinkProgram(p);

    glGetProgramiv(p, GL_LINK_STATUS, &compileStatus);

    if (GL_FALSE == compileStatus) {
        GLint maxLength = 0;
        glGetProgramiv(p, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(p, maxLength, &maxLength, &infoLog[0]);
    //    result.ok = false;
  //      result.errorMessage = infoLog.data();

        glDeleteProgram(p);
        glDeleteShader(vshader);
        glDeleteShader(fshader);

    }

    GLenum err = glGetError();
    if (err != 0) {
        return 0;
    }

    glDeleteShader(vshader);
    glDeleteShader(fshader);

    return p;

}


void init() {

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vboPos;
    float positions[] = {
        -0.5, 0.5,  0. ,   // top left
        -0.5, -0.5,  0. ,  // bottom left
        0.5, -0.5,    0.   // bottom right
    };
    glGenBuffers(1, &vboPos);
    glBindBuffer(GL_ARRAY_BUFFER, vboPos);
    glBufferData(GL_ARRAY_BUFFER, 12*4, positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    GLERR

    glBindVertexArray(0);
}



void render(GLuint shader) {
    glBindVertexArray(vao);
    glUseProgram(shader);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    GLERR
}

void initOpenGL(SDL_Window* window) {
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GLContext ctx = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(0);  // NO VSync

    GLenum r = glewInit();
    if (r != GLEW_OK) {
        return 2;
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}



int main(int argc, char** args) {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        SDL_Log("error initializing. %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("test 0.0.1", 300, 100, 800, 600, SDL_WINDOW_OPENGL);
    initOpenGL(window);

    glViewport(0, 0, 800, 600);
    Game* game = new RobotronicGame();

    game->init();

    bool running = true;
    std::vector<SDL_Event> frameEvents;
    while (running) {
        frameEvents.clear();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
            frameEvents.push_back(event);
        }

        glClearColor(0.5, 0.2, 0.1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        game->update();
        game->render(shader);

        SDL_GL_SwapWindow(window);


    }


    game->shutdown();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;


}
