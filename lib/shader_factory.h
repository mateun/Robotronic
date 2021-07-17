//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_SHADER_FACTORY_H
#define ROBOTRONIC_SHADER_FACTORY_H

#include <GL/glew.h>
#include <string>
#include <map>
#include "Shader.h"

class ShaderFactory {

public:
    ShaderFactory();
    GLuint getDefault2DShader();
    Shader* getDefault2DShaderObject();
    GLuint createFromFileNames(const std::string& vshaderFile, const std::string fshaderFile);
    GLuint createFromStrings(const std::string& vshaderSource, const std::string fshaderSource);
    void storeUnderKey(const std::string& key, GLuint shader);
    GLuint getByKey(const std::string& key);

private:
    void initDefaultShader();
    void initDefaultShaderObject();

private:
    static GLuint _default2DShader;
    static Shader* _default2DShaderObject;
    static std::map<std::string, GLuint>* _shaderCache;


};

#endif //ROBOTRONIC_SHADER_FACTORY_H
