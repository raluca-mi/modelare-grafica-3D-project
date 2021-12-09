#include<GL/glew.h>
#include<glfw3.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "Mesh.h"

#include<glm.hpp>
#include<gtc/matrix_transform.hpp>

#include"OBJLoader.h";

void drawDoor(Renderer& renderer, Shader& shader)
{
	float positions[] = {
			 -3.0f,  -1.5f, 0.0f, 0.0f,  //0
			  3.0f,  -1.5f, 1.0f, 0.0f,  //1
			  3.0f,   1.5f, 1.0f, 1.0f,  //2
			 -3.0f,   1.5f, 0.0f, 1.0f   //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}
void drawMainWindow(Renderer& renderer, Shader& shader)
{
	float positions[] = {
			 -3.0f,  -1.0f, 0.0f, 0.0f,  //0
			  3.0f,  -1.0f, 1.0f, 0.0f,  //1
			  3.0f,   1.0f, 1.0f, 1.0f,  //2
			 -3.0f,   1.0f, 0.0f, 1.0f   //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}
void drawLeftWindow(Renderer& renderer, Shader& shader)
{
	float positions[] = {
			 -0.7f,  -0.4f, 0.0f, 0.0f,  //0
			  0.7f,  -0.4f, 1.0f, 0.0f,  //1
			  0.7f,   0.4f, 1.0f, 1.0f,  //2
			 -0.7f,   0.4f, 0.0f, 1.0f   //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}
void drawRightWindow(Renderer& renderer, Shader& shader)
{
	float positions[] = {
			 -1.0f,  -0.9f, 0.0f, 0.0f,  //0
			  1.0f,  -0.9f, 1.0f, 0.0f,  //1
			  1.0f,   0.9f, 1.0f, 1.0f,  //2
			 -1.0f,   0.9f, 0.0f, 1.0f   //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}
void drawSign(Renderer& renderer, Shader& shader)
{
	float positions[] = {
			 -2.0f,  -0.5f, 0.0f, 0.0f,  //0
			  2.0f,  -0.5f, 1.0f, 0.0f,  //1
			  2.0f,   0.5f, 1.0f, 1.0f,  //2
			 -2.0f,   0.5f, 0.0f, 1.0f   //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}
void drawRailway(Renderer& renderer, Shader& shader)
{
	float positions[] = {
			 -18.0f,  -1.1f, 0.0f, 0.0f,  //0
			  18.0f,  -1.1f, 1.0f, 0.0f,  //1
			  18.0f,   1.1f, 1.0f, 1.0f,  //2
			 -18.0f,   1.1f, 0.0f, 1.0f   //3
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}

Mesh InitStationMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		// Vertex coords    //tex coords   

		//front
		 -11.5, -0.0,  0.0, 0.0f, 0.0f, //0 0
		  11.5, -0.0,  0.0, 1.0f, 0.0f, //1 1
		  11.5,  5.0,  0.0, 1.0f, 1.0f, //2 2
		 -11.5,  5.0,  0.0, 0.0f, 1.0f, //3 3

		 //back
		 -11.5, -0.0, -7.0, 1.0f, 0.0f, //4 4
		 -11.5,  5.0, -7.0, 1.0f, 1.0f, //5 5
		  11.5,  5.0, -7.0, 0.0f, 1.0f, //6 6
		  11.5, -0.0, -7.0, 0.0f, 0.0f, //7 7

		  //left
		 -11.5, -0.0, -7.0, 0.0f, 0.0f, //4 8
		 -11.5,  5.0, -7.0, 0.0f, 1.0f, //5 9
		 -11.5,  5.0,  0.0, 1.0f, 1.0f, //3 10
		 -11.5, -0.0,  0.0, 1.0f, 0.0f, //0 11

		 //right
		  11.5, -0.0,  0.0, 0.0f, 0.0f, //1 12
		  11.5, -0.0, -7.0, 1.0f, 0.0f, //7 13
		  11.5,  5.0, -7.0, 1.0f, 1.0f, //6 14
		  11.5,  5.0,  0.0, 0.0f, 1.0f, //2 15

		  //top
		  -11.5,  5.0,  0.0, 0.0f, 0.0f, //3 16
		   11.5,  5.0,  0.0, 1.0f, 0.0f, //2 17
		   11.5,  5.0, -7.0, 1.0f, 1.0f, //6 18
		  -11.5,  5.0, -7.0, 0.0f, 1.0f, //5 19

		  //bottom
		  -11.5, -0.0, -7.0, 0.0f, 0.0f, //4 20
		   11.5, -0.0, -7.0, 1.0f, 0.0f, //7 21
		   11.5, -0.0,  0.0, 1.0f, 1.0f, //1 22
		  -11.5, -0.0,  0.0, 0.0f, 1.0f  //0 23
	};

	std::vector<unsigned int> indices = {
		//front
		0,1,2, //down
		2,3,0, //up

		//left
		11,8,9,
		9,10,11,

		//back
		5,4,7,
		7,6,5,

		//right
		12,13,14,
		14,15,12,

		//bottom
		23,22,21,
		21,20,23,

		//top
		16,17,18,
		18,19,16
	};

	return Mesh(vertices, indices, texture);
}
Mesh InitStationRoofMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		// Vertex coords    //tex coords   

		//front
		 -12.5, -0.1,  1.0,  0.0f, 0.0f, //0 0
		  12.5, -0.1,  1.0,  1.0f, 0.0f, //1 1
		  8.0,   2.0,  -0.5, 1.0f, 1.0f, //2 2
		 -8.0,   2.0,  -0.5, 0.0f, 1.0f, //3 3

		 //back
		 -12.5, -0.1, -7.0, 1.0f, 0.0f, //4 4
		 -8.0,   2.0, -5.5, 1.0f, 1.0f, //5 5
		  8.0,   2.0, -5.5, 0.0f, 1.0f, //6 6
		  12.5, -0.1, -7.0, 0.0f, 0.0f, //7 7

		  //left
		 -12.5, -0.1, -7.0, 0.0f, 0.0f, //4 8
		 -8.0,   2.0, -5.5, 0.0f, 1.0f, //5 9
		 -8.0,   2.0, -0.5, 1.0f, 1.0f, //3 10
		 -12.5, -0.1,  1.0, 1.0f, 0.0f, //0 11

		 //right
		  12.5, -0.1,  1.0, 0.0f, 0.0f, //1 12
		  12.5, -0.1, -7.0, 1.0f, 0.0f, //7 13
		  8.0,   2.0,  -5.5, 1.0f,  1.0f, //6 14
		  8.0,   2.0,  -0.5, 0.0f,  1.0f, //2 15

		  //top
		  -8.0,  2.0,  -0.5, 0.0f, 0.0f, //3 16
		   8.0,  2.0,  -0.5, 1.0f, 0.0f, //2 17
		   8.0,  2.0,  -5.5, 1.0f, 1.0f, //6 18
		  -8.0,  2.0,  -5.5, 0.0f, 1.0f, //5 19

		  //bottom
		  -12.5, -0.1, -7.0, 0.0f, 0.0f, //4 20
		   12.5, -0.1, -7.0, 1.0f, 0.0f, //7 21
		   12.5, -0.1,  1.0, 1.0f, 1.0f, //1 22
		  -12.5, -0.1,  1.0, 0.0f, 1.0f  //0 23
	};

	std::vector<unsigned int> indices = {
		//front
		0,1,2, //down
		2,3,0, //up

		//left
		11,8,9,
		9,10,11,

		//back
		5,4,7,
		7,6,5,

		//right
		12,13,14,
		14,15,12,

		//bottom
		23,22,21,
		21,20,23,

		//top
		16,17,18,
		18,19,16
	};

	return Mesh(vertices, indices, texture);	
}
Mesh InitMainPlatform(const Texture& texture)
{
	std::vector<float> vertices={

		// Vertex coords    //tex coords   

		//front
		 -18.0, -6.0,  0.0, 0.0f, 0.0f, //0 0
		  18.0, -6.0,  0.0, 1.0f, 0.0f, //1 1
		  18.0,  6.0,  0.0, 1.0f, 1.0f, //2 2
		 -18.0,  6.0,  0.0, 0.0f, 1.0f, //3 3

		 //back
		 -18.0, -6.0, -0.3, 1.0f, 0.0f, //4 4
		 -18.0,  6.0, -0.3, 1.0f, 1.0f, //5 5
		  18.0,  6.0, -0.3, 0.0f, 1.0f, //6 6
		  18.0, -6.0, -0.3, 0.0f, 0.0f, //7 7

		  //left	   	  
		 -18.0, -6.0,  -0.3, 0.0f, 0.0f, //4 8
		 -18.0,  6.0,  -0.3, 0.0f, 1.0f, //5 9
		 -18.0,  6.0,   0.0, 1.0f, 1.0f, //3 10
		 -18.0, -6.0,   0.0, 1.0f, 0.0f, //0 11

		 //right
		  18.0, -6.0,  0.0, 0.0f, 0.0f, //1 12
		  18.0, -6.0, -0.3, 1.0f, 0.0f, //7 13
		  18.0,  6.0, -0.3, 1.0f, 1.0f, //6 14
		  18.0,  6.0,  0.0, 0.0f, 1.0f, //2 15

		  //top
		  -18.0,  6.0,  0.0, 0.0f, 0.0f, //3 16
		   18.0,  6.0,  0.0, 1.0f, 0.0f, //2 17
		   18.0,  6.0, -0.3, 1.0f, 1.0f, //6 18
		  -18.0,  6.0, -0.3, 0.0f, 1.0f, //5 19

		  //bottom
		  -18.0, -6.0, -0.3, 0.0f, 0.0f, //4 20
		   18.0, -6.0, -0.3, 1.0f, 0.0f, //7 21
		   18.0, -6.0,  0.0, 1.0f, 1.0f, //1 22
		  -18.0, -6.0,  0.0, 0.0f, 1.0f  //0 23
	};

	std::vector<unsigned int> indices = {
		//front
		0,1,2, //down
		2,3,0, //up

		//left
		11,8,9,
		9,10,11,

		//back
		5,4,7,
		7,6,5,

		//right
		12,13,14,
		14,15,12,

		//bottom
		23,22,21,
		21,20,23,

		//top
		16,17,18,
		18,19,16
	};

	return Mesh(vertices, indices, texture);
}
Mesh InitSecondPlatform(const Texture& texture)
{
	std::vector<float> vertices = {

		// Vertex coords    //tex coords   

		//front
		 -18.0, -0.8,  0.0, 0.0f, 0.0f, //0 0
		  18.0, -0.8,  0.0, 1.0f, 0.0f, //1 1
		  18.0,  0.8,  0.0, 1.0f, 1.0f, //2 2
		 -18.0,  0.8,  0.0, 0.0f, 1.0f, //3 3

		 //back
		 -18.0, -0.8, -0.3, 1.0f, 0.0f, //4 4
		 -18.0,  0.8, -0.3, 1.0f, 1.0f, //5 5
		  18.0,  0.8, -0.3, 0.0f, 1.0f, //6 6
		  18.0, -0.8, -0.3, 0.0f, 0.0f, //7 7

		  //left	   	  
		 -18.0, -0.8,  -0.3, 0.0f, 0.0f, //4 8
		 -18.0,  0.8,  -0.3, 0.0f, 1.0f, //5 9
		 -18.0,  0.8,   0.0, 1.0f, 1.0f, //3 10
		 -18.0, -0.8,   0.0, 1.0f, 0.0f, //0 11

		 //right
		  18.0, -0.8,  0.0, 0.0f, 0.0f, //1 12
		  18.0, -0.8, -0.3, 1.0f, 0.0f, //7 13
		  18.0,  0.8, -0.3, 1.0f, 1.0f, //6 14
		  18.0,  0.8,  0.0, 0.0f, 1.0f, //2 15

		  //top
		  -18.0,  0.8,  0.0, 0.0f, 0.0f, //3 16
		   18.0,  0.8,  0.0, 1.0f, 0.0f, //2 17
		   18.0,  0.8, -0.3, 1.0f, 1.0f, //6 18
		  -18.0,  0.8, -0.3, 0.0f, 1.0f, //5 19

		  //bottom
		  -18.0, -0.8, -0.3, 0.0f, 0.0f, //4 20
		   18.0, -0.8, -0.3, 1.0f, 0.0f, //7 21
		   18.0, -0.8,  0.0, 1.0f, 1.0f, //1 22
		  -18.0, -0.8,  0.0, 0.0f, 1.0f  //0 23
	};

	std::vector<unsigned int> indices = {
		//front
		0,1,2, //down
		2,3,0, //up

		//left
		11,8,9,
		9,10,11,

		//back
		5,4,7,
		7,6,5,

		//right
		12,13,14,
		14,15,12,

		//bottom
		23,22,21,
		21,20,23,

		//top
		16,17,18,
		18,19,16
	};

	return Mesh(vertices, indices, texture);
}

int main(void)
{
	/* Initializing the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Creating a window */
	float window_height = 800.0f, window_width = 1850.0f;
	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Train simulator", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//Initiaziting glew
	glewInit();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Set background color
	glClearColor(0.5f, 0.7f, 0.8f, 1.0f);

	//Set up the projection and view matrix
	glm::mat4 proj = glm::ortho(0.0f, window_width, 0.0f, window_height, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(0, 200, 0));

	//Loading shader
	Shader shader("res/shaders/object.shader");
	shader.Bind();

	//Loading textures
	Texture station_texture("res/textures/brickss.jpg");
	Texture station_roof_texture("res/textures/roof.jpg");
	Texture station_platform("res/textures/platform.jpg");

	Texture station_door_texture("res/textures/door.jpg");
	Texture station_windows_texture("res/textures/windows.jpg");
	Texture station_left_window_texture("res/textures/left_windows.jpg");
	Texture station_right_window_texture("res/textures/right_window.jpg");
	Texture station_sign_texture("res/textures/sign.jpg");
	Texture railway("res/textures/railway.jpg");

	Texture trainTexture("res/textures/train.png");

	// Initialize camera
	Camera camera(window_width, window_height, glm::vec3(0.0f, 5.0f, 10.0f));
	camera.SetPitch(-10.0f);
	float last_frame = 0.0f, delta_time;
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwSetCursorPos(window, (window_width / 2), (window_height / 2));

	{
		Renderer renderer;

		glEnable(GL_DEPTH_TEST);

		//loading train model from .obj
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
		bool res = loadOBJ("res/models/train.obj", vertices, indices);
		

		//Loading meshes
		Mesh trainStation = InitStationMesh(station_texture);
		Mesh trainStationRoof = InitStationRoofMesh(station_roof_texture);
		Mesh mainPlatform = InitMainPlatform(station_platform);
		Mesh secondPlatform = InitSecondPlatform(station_platform);
		Mesh train(vertices,indices,trainTexture);
		float rot_angle = 0.0f;

		while (!glfwWindowShouldClose(window))
		{
			//Render here
			renderer.Clear();
			rot_angle += 0.02f;

			//Getting delta time
			float current_frame = static_cast<float>(glfwGetTime());
			delta_time = current_frame - last_frame;
			last_frame = current_frame;

			//processing user input
			camera.ProcessInput(window, delta_time);

			//Draw train model
			{
				glm::mat4 model = glm::mat4(0.7f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 5.1f ));
				model = glm::rotate(model, glm::radians(360.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);
				train.Draw(camera, shader, renderer);
			}
			//Draw train station building
			{
				glm::mat4 model = glm::mat4(1.0f);
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);

				trainStation.Draw(camera, shader, renderer);
			}

			//Draw train station building roof 
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 5.0f, -0.5f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				
				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);

				trainStationRoof.Draw(camera, shader, renderer);
			}

			//Draw train station door
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_door_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawDoor(renderer, shader);
			}

			//Draw train station front window_1
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-7.0f, 2.43f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_windows_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawMainWindow(renderer, shader);
			}

			//Draw train station front window_2
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(7.0f, 2.43f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_windows_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawMainWindow(renderer, shader);
			}

			//Draw left window_1
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -5.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_left_window_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawLeftWindow(renderer, shader);
			}

			//Draw left window_2
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -2.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_left_window_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawLeftWindow(renderer, shader);
			}

			//Draw right window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(11.52f, 2.6f, -3.5f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_right_window_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawRightWindow(renderer, shader);
			}

			//Draw train station sign
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 4.0f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				station_sign_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawSign(renderer, shader);
			}

			//Draw main platform
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, -2.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);

				mainPlatform.Draw(camera, shader, renderer);
			}


			//Draw railway
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 5.1f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;
				railway.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawRailway(renderer, shader);
			}

			//Draw second platform
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 7.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				shader.Bind();
				shader.SetUniformMat4f("u_MVP", mvp);

				secondPlatform.Draw(camera, shader, renderer);
			}

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}