#version 430 core
layout (location = 0) in vec3 aPos; // position has attribute position 0
layout (location = 1) in vec3 aColor; // color has attribute position 1
layout(location = 0) uniform vec3 offSet;
out vec3 ourColor; // output a color to the fragment shader
void main()
{
    vec3 fPos = aPos+offSet;
    gl_Position = vec4(fPos, 1.0);
    ourColor = fPos; // set ourColor to input color from the vertex data
}