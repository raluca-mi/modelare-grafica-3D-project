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
		 -10.5, -0.1,  0.0, 0.0f, 0.0f, //0 0
		  10.5, -0.1,  0.0, 1.0f, 0.0f, //1 1
		  10.5,  5.0,  0.0, 1.0f, 1.0f, //2 2
		 -10.5,  5.0,  0.0, 0.0f, 1.0f, //3 3

		 //back
		 -10.5, -0.1, -7.0, 1.0f, 0.0f, //4 4
		 -10.5,  5.0, -7.0, 1.0f, 1.0f, //5 5
		  10.5,  5.0, -7.0, 0.0f, 1.0f, //6 6
		  10.5, -0.1, -7.0, 0.0f, 0.0f, //7 7

		  //left
		 -10.5, -0.1, -7.0, 0.0f, 0.0f, //4 8
		 -10.5,  5.0, -7.0, 0.0f, 1.0f, //5 9
		 -10.5,  5.0,  0.0, 1.0f, 1.0f, //3 10
		 -10.5, -0.1,  0.0, 1.0f, 0.0f, //0 11

		 //right
		  10.5, -0.1,  0.0, 0.0f, 0.0f, //1 12
		  10.5, -0.1, -7.0, 1.0f, 0.0f, //7 13
		  10.5,  5.0, -7.0, 1.0f, 1.0f, //6 14
		  10.5,  5.0,  0.0, 0.0f, 1.0f, //2 15

		  //top
		  -10.5,  5.0,  0.0, 0.0f, 0.0f, //3 16
		   10.5,  5.0,  0.0, 1.0f, 0.0f, //2 17
		   10.5,  5.0, -7.0, 1.0f, 1.0f, //6 18
		  -10.5,  5.0, -7.0, 0.0f, 1.0f, //5 19

		  //bottom
		  -10.5, -0.1, -7.0, 0.0f, 0.0f, //4 20
		   10.5, -0.1, -7.0, 1.0f, 0.0f, //7 21
		   10.5, -0.1,  0.0, 1.0f, 1.0f, //1 22
		  -10.5, -0.1,  0.0, 0.0f, 1.0f  //0 23
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
		 -12.5, -0.1,  1.0, 0.0f, 0.0f, //0 0
		  12.5, -0.1,  1.0, 1.0f, 0.0f, //1 1
		  12.5,  2.0,  1.0, 1.0f, 1.0f, //2 2
		 -12.5,  2.0,  1.0, 0.0f, 1.0f, //3 3

		 //back
		 -12.5, -0.1, -7.0, 1.0f, 0.0f, //4 4
		 -12.5,  2.0, -7.0, 1.0f, 1.0f, //5 5
		  12.5,  2.0, -7.0, 0.0f, 1.0f, //6 6
		  12.5, -0.1, -7.0, 0.0f, 0.0f, //7 7

		  //left
		 -12.5, -0.1, -7.0, 0.0f, 0.0f, //4 8
		 -12.5,  2.0, -7.0, 0.0f, 1.0f, //5 9
		 -12.5,  2.0,  1.0, 1.0f, 1.0f, //3 10
		 -12.5, -0.1,  1.0, 1.0f, 0.0f, //0 11

		 //right
		  12.5, -0.1,  1.0, 0.0f, 0.0f, //1 12
		  12.5, -0.1, -7.0, 1.0f, 0.0f, //7 13
		  12.5,  2.0, -7.0, 1.0f, 1.0f, //6 14
		  12.5,  2.0,  1.0, 0.0f, 1.0f, //2 15

		  //top
		  -12.5,  2.0,  1.0, 0.0f, 0.0f, //3 16
		   12.5,  2.0,  1.0, 1.0f, 0.0f, //2 17
		   12.5,  2.0, -7.0, 1.0f, 1.0f, //6 18
		  -12.5,  2.0, -7.0, 0.0f, 1.0f, //5 19

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

void drawWindow(Renderer& renderer, Shader& shader)
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
		std::cout << "Error!";
	std::cout << glGetString(GL_VERSION) << std::endl;

	//Set background color
	glClearColor(0.5f, 0.7f, 0.8f, 1.0f);

	{
		//Blending
		GlCall(glEnable(GL_BLEND));
		GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		glm::mat4 proj = glm::ortho(0.0f, witdth, 0.0f, height, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(0, 200, 0));

		Renderer renderer;
		Shader shader("res/shaders/Basic.shader");
		Texture station_texture("res/textures/walls.jpg");
		Texture station_roof_texture("res/textures/roof.jpg");
		Texture station_door_texture("res/textures/door.jpg");
		Texture station_windows_texture("res/textures/windows.jpg");
		Texture station_sign_texture("res/textures/sign.jpg");


		float delta_time = 1.0f;
		float last_frame = 0.0f;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		glfwSetCursorPos(window, witdth / 2, height / 2);

		Camera cam(960,480,glm::vec3(0.0f, 0.0f, 1.0f));

		glEnable(GL_DEPTH_TEST);

		float movement = 0.0f;

		while (!glfwWindowShouldClose(window))
		{
			//Render here
			renderer.Clear();

			//Set up camera
			float current_frame = glfwGetTime();
			delta_time = current_frame - last_frame;
			last_frame = current_frame;
			cam.ProcessInput(window,delta_time);

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
				model = glm::translate(model, glm::vec3(0.0f, 1.43f, 0.05f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_door_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawDoor(renderer, shader);
			}

			//Draw train station window_1
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-7.0f, 2.43f, 0.05f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_windows_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawWindow(renderer, shader);
			}

			//Draw train station window_2
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(7.0f, 2.43f, 0.05f));
				glm::mat4 mvp = cam.GetProjectionMatrix() * cam.GetViewMatrix() * model;
				station_windows_texture.Bind();
				shader.Bind();
				shader.SetUniform1i("u_Texture", 0);
				shader.SetUniformMat4f("u_MVP", mvp);

				drawWindow(renderer, shader);
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

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}