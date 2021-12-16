#shader vertex
#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 u_VP;
uniform mat4 u_ModelMatrix;

void main()
{
	//projection
	gl_Position = u_VP * u_ModelMatrix * vec4(position, 1.0);
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
	color = u_Color;
};