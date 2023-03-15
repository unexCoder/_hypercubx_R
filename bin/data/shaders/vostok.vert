#version 410

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vData
{
    vec4 color;
}vertex;

void main()
{
    gl_Position = vec4(aPos, 1.0f);
    vertex.color = aColor;
}
