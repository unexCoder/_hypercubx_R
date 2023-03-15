#version 410

layout (lines) in;
layout(triangle_strip,max_vertices=4) out;

in vData
{
    vec4 color;
}vertices[];

out fData
{
    vec4 color;
}frag;

uniform float thickness;
uniform vec3 lightDir;
uniform mat4 modelViewProjectionMatrix;

void main() {
    
    vec3 p0 = gl_in[0].gl_Position.xyz;
    vec3 p1 = gl_in[1].gl_Position.xyz;
    vec3 up = vec3(0, 0, 1);    // arbitrary up vector
    
    vec3 dir = normalize(p1 - p0);            // normalized direction vector from p0 to p1
    vec3 right = normalize(cross(dir, up));    // right vector
    vec3 norm = cross(right, dir);
    float fColMult = abs(dot(norm, lightDir));
    vec4 colMult = vec4(fColMult, fColMult, fColMult, 1.0);
    
    right *= thickness;

    gl_Position =  modelViewProjectionMatrix * vec4(p0 - right, 1.0);
    //gl_FrontColor = gl_FrontColorIn[0] * colMult;
    frag.color = vertices[0].color * colMult * 2.0;
    EmitVertex();
    
    gl_Position =   modelViewProjectionMatrix * vec4(p0 + right, 1.0);
    //gl_FrontColor = gl_FrontColorIn[0] * colMult;
    frag.color = vertices[0].color * colMult * 2.0;
    EmitVertex();
    
    gl_Position =   modelViewProjectionMatrix * vec4(p1 - right, 1.0);
    //gl_FrontColor = gl_FrontColorIn[1] * colMult;
    frag.color = vertices[1].color * colMult * 2.0;
    EmitVertex();
    
    gl_Position =   modelViewProjectionMatrix * vec4(p1 + right, 1.0);
    frag.color = vertices[1].color * colMult * 2.0;
    //gl_FrontColor = gl_FrontColorIn[1] * colMult;
    EmitVertex();
    EndPrimitive();
}

