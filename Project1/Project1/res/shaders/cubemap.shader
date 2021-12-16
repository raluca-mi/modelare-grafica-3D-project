#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 u_VP;
uniform mat4 u_ModelMatrix;

void main()
{
    gl_Position = u_VP * u_ModelMatrix * vec4(aPos, 1.0);
    TexCoords=aPos;
}

#shader fragment
#version 330 core
out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{
    FragColor = texture(skybox, TexCoords);
}