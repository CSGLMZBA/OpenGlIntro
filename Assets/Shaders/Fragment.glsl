#version 430 core
out vec4 FragColor;
in vec3 ourColor;
layout(location = 0) uniform float Red;
void main()
{
    FragColor = vec4(ourColor.xy,Red, 1.0);
}