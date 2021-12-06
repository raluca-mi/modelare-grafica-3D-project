#include<GL/glew.h>
#include<glfw3.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include"Renderer.h"

#include"VertexBufferLayout.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"VertexArray.h"
#include"Shader.h"
#include"Texture.h"
#include "Camera.h"

#include<glm.hpp>
#include<gtc/matrix_transform.hpp>


void drawStation(Renderer& renderer, Shader& shader)
{
	float positions[] = {
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

	unsigned int indices[] = {
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

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}

void drawRoof(Renderer& renderer, Shader& shader)
{
	float positions[] = {
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

	unsigned int indices[] = {
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

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}

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

void drawPlatform_1(Renderer& renderer, Shader& shader)
{
	float positions[] = {
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

	unsigned int indices[] = {
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

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(3);
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

void drawPlatform_2(Renderer& renderer, Shader& shader)
{
	float positions[] = {
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

	unsigned int indices[] = {
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

	VertexArray va;
	VertexBuffer vb(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

	va.Unbind();
	vb.Unbind();
	ib.Unbind();

	renderer.Draw(va, ib, shader);
}


int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	float witdth = 1600.0f;
	float height = 800.0f;

	//Create the window
	window = glfwCreateWindow((int)witdth, (int)height, "Train simulator", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	//Init glew
	if (glewInit() != GLEW_OK)
		std::cout << "Error starting glew!";

	//Set background color
	glClearColor(0.5f, 0.7f, 0.8f, 1.0f);

	{
		//Blending
		GlCall(glEnable(GL_BLEND));
		GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		//Set up the projection and view matrix
		glm::mat4 proj = glm::ortho(0.0f, witdth, 0.0f, height, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(0, 200, 0));

		Renderer renderer;
		Shader shader("res/shaders/Basic.shader");
		Texture station_texture("res/textures/brickss.jpg");
		Texture station_roof_texture("res/textures/roof.jpg");
		Texture station_door_texture("res/textures/door.jpg");
		Texture station_windows_texture("res/textures/windows.jpg");
		Texture station_left_window_texture("res/textures/left_windows.jpg");
		Texture station_right_window_texture("res/textures/right_window.jpg");
		Texture station_sign_texture("res/textures/sign.jpg");
		Texture station_platform("res/textures/platform.jpg");
		Texture railway("res/textures/railway.jpg");

		float delta_time = 1.0f;
		float last_frame = 0.0f;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		glfwSetCursorPos(window, witdth / 2, height / 2);

		Camera cam(960, 480, glm::vec3(0.0f, 0.0f, 1.0f));

		glEnable(GL_DEPTH_TEST);

		while (!glfwWindowShouldClose(window))
		{
			//Render here
			renderer.Clear();

			//Set up camera
			float current_frame = glfwGetTime();
			delta_time = current_frame - last_frame;
			last_frame = current_frame;
			cam.ProcessInput(window, delta_time);

			//Draw train station building
			{
				glm::mat4 model = glm::mat4(1.0f);
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawStation(renderer, shader);
			}

			//Draw train station building roof 
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 5.0f, -0.5f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_roof_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawRoof(renderer, shader);
			}

			//Draw train station door
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.05f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
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
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_platform.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawPlatform_1(renderer, shader);
			}


			//Draw railway
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 5.1f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				railway.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawRailway(renderer, shader);
			}

			//Draw platform_2
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 7.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_platform.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawPlatform_2(renderer, shader);
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