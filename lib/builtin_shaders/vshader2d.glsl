#version 430

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uvs;

layout (location = 6) uniform mat4 model;
layout (location = 7) uniform mat4 view;
layout (location = 8) uniform mat4 proj;

out vec2 fs_uvs;

void main() {
    gl_Position = proj * view * model * vec4(pos, 1);
    fs_uvs = uvs;


}