#version 410

out vec4 FragColor;
uniform float overdrive;

in fData
{
    vec4 color;
}frag_in;

void main()
{
    FragColor = frag_in.color*overdrive;
}
