#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 tex_coord;
layout(location = 2) in vec3 normals;

out vec2 v_tex_coord;
out vec3 v_normals;
out vec3 current_position;

uniform mat4 u_ProjectionMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ModelMatrix;

void main()
{
	//calculating the position of the object
	current_position = vec3(u_ModelMatrix * vec4(position, 1.0f));

	//projection
	gl_Position = u_ProjectionMatrix * u_ViewMatrix * vec4(current_position, 1.0);

	//for texture
	v_tex_coord = tex_coord;

	v_normals = normals;
};



#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_tex_coord;
in vec3 v_normals;
in vec3 current_position;

uniform vec4 u_LightColor;
uniform vec3 u_LightPosition;
uniform vec3 u_CamPosition;
uniform sampler2D u_Texture;

void main()
{
	//ambiental light
	float ambient = 0.2f;

	//diffuse light
	vec3 normal = normalize(v_normals);
	vec3 light_direction = normalize(u_LightPosition - current_position);
	float diffuse = max(dot(normal, light_direction), 0.0f);

	//specular light
	float specular_light = 0.5f;
	vec3 view_direction = normalize(u_CamPosition - current_position);
	vec3 reflection_direction = reflect(-light_direction, normal);
	float spec_amount = pow(max(dot(view_direction, reflection_direction), 0.0f), 32);
	float specular = spec_amount * specular_light;

	//texture
	vec4 tex_color = texture(u_Texture, v_tex_coord);

	color = tex_color * u_LightColor * (ambient + diffuse + specular);
	color.a = 1.0f;
};