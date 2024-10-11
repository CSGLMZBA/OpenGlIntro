#version 450 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCoord;
layout(location = 0)uniform sampler2D texture1;
layout(location = 1)uniform sampler2D texture2;
layout(location = 2)uniform float texture3;
void main()
{
    FragColor = mix(texture(texture1, TexCoord),
    texture(texture2, TexCoord), 0+texture3);
}