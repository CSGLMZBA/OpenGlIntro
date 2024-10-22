#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec3 ourColor;
out vec2 TexCoord;
layout (location = 4) uniform mat4 model;
layout (location = 5) uniform mat4 view;
layout (location = 6) uniform mat4 projection;
void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}