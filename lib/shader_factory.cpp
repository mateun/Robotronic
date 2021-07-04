//
// Created by mgrus on 04/07/2021.
//

#include <vector>
#include <SDL.h>
#include "shader_factory.h"
#include "filesutils.h"

GLuint ShaderFactory::_default2DShader = 0;

ShaderFactory::ShaderFactory() {

}

GLuint ShaderFactory::getDefault2DShader() {
    if (!_default2DShader) {
        initDefaultShader();
    }

    return _default2DShader;
}

GLuint ShaderFactory::createFromFileNames(const std::string &vshaderFile, const std::string fshaderFile) {
    std::string vsource = f_read_file(vshaderFile);
    std::string fsource = f_read_file(fshaderFile);
    return createFromStrings(vsource, fsource);
}

GLuint ShaderFactory::createFromStrings(const std::string &vertexShaderSource, const std::string fragmentShaderSource) {
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

void ShaderFactory::initDefaultShader() {
    std::string basePath(SDL_GetBasePath());
    _default2DShader = createFromFileNames(basePath + "../lib/builtin_shaders/vshader2d.glsl",
                                           basePath + "../lib/builtin_shaders/fshader2d.glsl");

}

