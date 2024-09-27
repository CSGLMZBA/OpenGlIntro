#version 430 core
out vec4 FragColor;
in vec3 ourColor;
void main()
{
    FragColor = vec4(0.3-ourColor, 1.0);
}