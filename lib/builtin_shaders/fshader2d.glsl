#version 430

layout(binding = 0) uniform sampler2D colorTex;

layout (location = 100) uniform vec4 singleColor;
layout (location = 101) uniform bool useTexture = false;

in vec2 fs_uvs;
out vec4 frag_color;

void main() {
    if (useTexture) {
        frag_color = texture(colorTex, fs_uvs);
    } else {
        frag_color = singleColor;
    }

}