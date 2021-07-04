#version 430

layout (location = 100) uniform vec4 singleColor;

out vec4 frag_color;

void main() {
    frag_color = singleColor;
}