#include<GL/glew.h>
#include<glfw3.h>
#include<GL/glut.h>
#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "Mesh.h"
#include"OBJLoader.h"
#include"Terrain.h"
#include "Skybox.h"


Mesh InitCampinaStationMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	   Texture coords        Normals*/

	  //front
	   -11.5, -0.0,  0.0,		0.0f, 0.0f,			0.0f,  0.0f,  1.0f,	//0 0
		11.5, -0.0,  0.0,		1.0f, 0.0f,			0.0f,  0.0f,  1.0f,	//1 1
		11.5,  5.0,  0.0,		1.0f, 1.0f,			0.0f,  0.0f,  1.0f,	//2 2
	   -11.5,  5.0,  0.0,		0.0f, 1.0f,			0.0f,  0.0f,  1.0f,	//3 3

	  //back
	   -11.5, -0.0, -7.0,		1.0f, 0.0f,			0.0f,  0.0f, -1.0f,	//4 4
	   -11.5,  5.0, -7.0,		1.0f, 1.0f,			0.0f,  0.0f, -1.0f,	//5 5
		11.5,  5.0, -7.0,		0.0f, 1.0f,			0.0f,  0.0f, -1.0f,	//6 6
		11.5, -0.0, -7.0,		0.0f, 0.0f,			0.0f,  0.0f, -1.0f,	//7 7

	   //left
	   -11.5, -0.0, -7.0,		0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,	//4 8
	   -11.5,  5.0, -7.0,		0.0f, 1.0f,			-1.0f,  0.0f, 0.0f,	//5 9
	   -11.5,  5.0,  0.0,		1.0f, 1.0f,			-1.0f,  0.0f, 0.0f,	//3 10
	   -11.5, -0.0,  0.0,		1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,	//0 11

	   //right
		11.5, -0.0,  0.0,		0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//1 12
		11.5, -0.0, -7.0,		1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//7 13
		11.5,  5.0, -7.0,		1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//6 14
		11.5,  5.0,  0.0,		0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//2 15

		//top
		-11.5,  5.0,  0.0,		0.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//3 16
		 11.5,  5.0,  0.0,		1.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//2 17
		 11.5,  5.0, -7.0,		1.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//6 18
		-11.5,  5.0, -7.0,		0.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//5 19

		//bottom
		-11.5, -0.0, -7.0,		0.0f, 0.0f,			0.0f,  -1.0f, 0.0f,	//4 20
		 11.5, -0.0, -7.0,		1.0f, 0.0f,			0.0f,  -1.0f, 0.0f,	//7 21
		 11.5, -0.0,  0.0,		1.0f, 1.0f,			0.0f,  -1.0f, 0.0f,	//1 22
		-11.5, -0.0,  0.0,		0.0f, 1.0f,			0.0f,  -1.0f, 0.0f,	//0 23
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
Mesh InitCampinaStationRoofMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords				 Texture coords            Normals*/

	  //front
		-12.5, -0.1,  1.0,			 0.0f,0.0f,			    0.0f,  0.0f,  1.0f,		//0
		-8.0,  -0.1,  1.0,			 1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//1
		-8.0,	2,	 -0.5,			 1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//2

	   -8.0,  -0.1,   1.0,			 0.0f, 0.0f,		    0.0f,  0.0f,  1.0f,		//3
	   -8.0,   2,    -0.5,			 0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//4
	   -4.0,  -0.1,   1.0,			 1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//5
	   -4.0,   2,    -0.5,			 1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//6

	   -4.0,  -0.1,   1.0,			 0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//7
	   -4.0,   2,    -0.5,			 0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//8
		0.0,  -0.1,   1.0,			 1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//9
		0.0,   2,    -0.5,			 1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//10

	   0.0,  -0.1,   1.0,			 0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//11
	   0.0,   2,    -0.5,			 0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//12
	   4.0,  -0.1,   1.0,			 1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//13
	   4.0,   2,    -0.5,			 1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//14

	   4.0,  -0.1,   1.0,			 0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//15
	   4.0,   2,    -0.5,			 0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//16
	   8.0,  -0.1,   1.0,			 1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//17
	   8.0,   2,    -0.5,			 1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//18

	  12.5, -0.1,  1.0,				 0.0f,0.0f,             0.0f,  0.0f,  1.0f,		 //19
	  8.0,  -0.1,  1.0,				 1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		 //20
	  8.0,   2,   -0.5,				 1.0f, 1.0f,		    0.0f,  0.0f,  1.0f,		 //21
	   //back

		 -12.5,   -0.1,  -7.0,     0.0f,0.0f,        0.0f,  0.0f,  -1.0f, //22
		-8.0,   -0.1,  -7.0,    1.0f, 0.0f,		  0.0f,  0.0f,  -1.0f, //23
		-8.0,  2, -5.5,    1.0f, 1.0f,		  0.0f,  0.0f,  -1.0f, //24

	   -8.0,    -0.1,   -7.0,    0.0f, 0.0f,		    0.0f,  0.0f,  -1.0f,//25
	   -8.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//26
	   -4.0,    -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//27
	   -4.0,   2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//28

	   -4.0,    -0.1,   -7.0,    0.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//29
	   -4.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//30
	   0.0,     -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//31
	   0.0,    2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//32

	   0.0,    -0.1,   -7.0,    0.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//33
	   0.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//34
	   4.0,     -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//35
	   4.0,    2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//36

	   4.0,    -0.1,   -7.0,    0.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//37
	   4.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//38
	   8.0,     -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  -1.0f,//39
	   8.0,    2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  -1.0f,//40

	  12.5,   -0.1,  -7.0,     0.0f,0.0f,            0.0f,  0.0f,  -1.0f, //41
	   8.0,    -0.1,  -7.0,     1.0f, 0.0f,			0.0f,  0.0f,  -1.0f, //42
	   8.0,   2,  -5.5,    1.0f, 1.0f,		    0.0f,  0.0f,  -1.0f, //43

		//top
		-8.0,  2.0,  -0.5,		0.0f, 0.0f,			0.0f,  1.0f, 0.0f,				//44
		 8.0,  2.0,  -0.5,		1.0f, 0.0f,			0.0f,  1.0f, 0.0f,				//45
		 8.0,  2.0,  -5.5,		1.0f, 1.0f,			0.0f,  1.0f, 0.0f,				//46
		-8.0,  2.0,  -5.5,		0.0f, 1.0f,			0.0f,  1.0f, 0.0f,				//47

		//bottom
		-12.5, -0.1, -7.0,		0.0f, 0.0f,			0.0f,  -1.0f, 0.0f,				//48
		 12.5, -0.1, -7.0,		1.0f, 0.0f,			0.0f,  -1.0f, 0.0f,				//49
		 12.5, -0.1,  1.0,		1.0f, 1.0f,			0.0f,  -1.0f, 0.0f,				//50
		-12.5, -0.1,  1.0,		0.0f, 1.0f,			0.0f,  -1.0f, 0.0f,				//51


	   //right

		12.5, -0.1, -7.0,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//52
		12.5, -0.1, -5.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//53
		8.0,   2.0, -5.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//54

		12.5, -0.1, -5.5,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//55
		8.0,   2.0, -5.5,			1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//56
		12.5, -0.1, -4.0,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//57
		8.0,   2.0, -4.0,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//58

		12.5, -0.1, -4.0,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//59
		8.0,   2.0, -4.0,			1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//60
		12.5, -0.1, -2.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//61
		8.0,   2.0, -2.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//62

		12.5, -0.1, -2.5,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//63
		8.0,   2.0, -2.5,			1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//64
		12.5, -0.1, -0.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//65
		8.0,   2.0, -0.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//66



		12.5, -0.1,  1.0,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//67
		12.5, -0.1, -0.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//68
		8.0,   2.0, -0.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//69

		////left
		-12.5, -0.1, -7.0,			1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//70
		-12.5, -0.1, -5.5,			0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//71
		-8.0,   2.0, -5.5,			0.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//72

		-12.5, -0.1, -5.5,			1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//73
		-8.0,   2.0, -5.5,			1.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//74
		-12.5, -0.1, -4.0,			0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//75
		-8.0,   2.0, -4.0,			0.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//76

		-12.5, -0.1, -4.0,			1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//77
		-8.0,   2.0, -4.0,			1.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//78
		-12.5, -0.1, -2.5,			0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//79
		-8.0,   2.0, -2.5,			0.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//80

		-12.5, -0.1, -2.5,			1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//81
		-8.0,   2.0, -2.5,			1.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//82
		-12.5, -0.1, -0.5,			0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//83
		-8.0,   2.0, -0.5,			0.0f,  1.0f,		-1.0f,  0.0f, 0.0f,		//84

		-12.5, -0.1,  1.0,			1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//67
		-12.5, -0.1, -0.5,			0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//68
		-8.0,   2.0, -0.5,			0.0f, 1.0f,		    -1.0f,  0.0f, 0.0f,		//69

	};

	std::vector<unsigned int> indices = {
		//front
		0,1,2,

		3,5,6,
		3,4,6,

		7,9,10,
		7,8,10,

		11,13,14,
		11,12,14,

		15,17,18,
		15,16,18,

		19,20,21,


		//back
		22,23,24,

		25,27,28,
		25,26,28,

		29,31,32,
		29,30,32,

		33,35,36,
		33,34,36,

		37,39,40,
		37,38,40,

		41,42,43,

		//bottom
		51,50,49,
		49,48,52,

		//top
		44,45,46,
		46,47,44,

		//right
		52,53,54,

		55,57,58,
		55,56,58,

		59,61,62,
		59,60,62,

		63,65,66,
		63,64,66,

		67,68,69,

		//left
		70,71,72,

		73,75,76,
		73,74,76,

		77,79,80,
		77,78,80,

		81,83,84,
		81,82,84,

		85,86,87

	};

	return Mesh(vertices, indices, texture);
}
Mesh InitCampinaDoorStationMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords			  Texture coords        Normals*/

		 -3.0f,  -1.5f,	0.0f,		0.0f, 0.0f,		 0.0f,  0.0f,  1.0f,	//0
		  3.0f,  -1.5f,	0.0f,		1.0f, 0.0f,		 0.0f,  0.0f,  1.0f,	//1
		  3.0f,   1.5f,	0.0f,		1.0f, 1.0f,		 0.0f,  0.0f,  1.0f,	//2
		 -3.0f,   1.5f,	0.0f,		0.0f, 1.0f,		 0.0f,  0.0f,  1.0f,	//3
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);
}
Mesh InitCampinaMainWindowsMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	          Texture coords        Normals*/

		 -3.0f,  -1.0f, 0.0f,		0.0f, 0.0f,			0.0f,  0.0f,  1.0f,//0
		  3.0f,  -1.0f, 0.0f,		1.0f, 0.0f,			0.0f,  0.0f,  1.0f,//1
		  3.0f,   1.0f, 0.0f,		1.0f, 1.0f,			0.0f,  0.0f,  1.0f,//2
		 -3.0f,   1.0f, 0.0f,		0.0f, 1.0f,			0.0f,  0.0f,  1.0f,//3
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);
}
Mesh InitCampinaLeftWindowMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	            Texture coords        Normals*/

		 -0.7f,  -0.4f, 0.0f,		0.0f, 0.0f,		-1.0f,  0.0f,  0.0f,//0
		  0.7f,  -0.4f, 0.0f,		1.0f, 0.0f,		-1.0f,  0.0f,  0.0f,//1
		  0.7f,   0.4f, 0.0f,		1.0f, 1.0f,		-1.0f,  0.0f,  0.0f,//2
		 -0.7f,   0.4f, 0.0f,		0.0f, 1.0f,		-1.0f,  0.0f,  0.0f,//3
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);
}
Mesh InitCampinaRightWindowMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	          Texture coords        Normals*/
		 -1.0f,  -0.9f, 0.0f,		0.0f, 0.0f,		1.0f,  0.0f,  0.0f,//0
		  1.0f,  -0.9f, 0.0f,		1.0f, 0.0f,		1.0f,  0.0f,  0.0f,//1
		  1.0f,   0.9f, 0.0f,		1.0f, 1.0f,		1.0f,  0.0f,  0.0f,//2
		 -1.0f,   0.9f, 0.0f,		0.0f, 1.0f,		1.0f,  0.0f,  0.0f,//3
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);
}

Mesh InitMainPlatformMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	       Texture coords            Normals*/

		//front
		 -18.0, -0.1,  0.0,		0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//0 0
		  18.0, -0.1,  0.0,		1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//1 1
		  18.0,  0.1,  0.0,		1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//2 2
		 -18.0,  0.1,  0.0,		0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//3 3

		 //back
		 -18.0, -0.1, -14.0,		1.0f, 0.0f,			0.0f,  0.0f, -1.0f,		//4 4
		 -18.0,  0.1, -14.0,		1.0f, 1.0f,			0.0f,  0.0f, -1.0f,		//5 5
		  18.0,  0.1, -14.0,		0.0f, 1.0f,			0.0f,  0.0f, -1.0f,		//6 6
		  18.0, -0.1, -14.0,		0.0f, 0.0f,			0.0f,  0.0f, -1.0f,		//7 7

		  //left	   	  
		 -18.0, -0.1,  -14.0,	0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//4 8
		 -18.0,  0.1,  -14.0,	0.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//5 9
		 -18.0,  0.1,   0.0,	1.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//3 10
		 -18.0, -0.1,   0.0,	1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//0 11

		 //right
		  18.0, -0.1,  0.0,		0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//1 12
		  18.0, -0.1, -14.0,		1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//7 13
		  18.0,  0.1,  -14.0,		1.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//6 14
		  18.0,  0.1,   0.0,		0.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//2 15

		  //top
		  -18.0, 0.1,  0.0,	0.0f, 0.0f,			    0.0f,  1.0f, 0.0f,		//3 16
		   18.0, 0.1,  0.0,	1.0f, 0.0f,			    0.0f,  1.0f, 0.0f,		//2 17
		   18.0, 0.1, -14.0,	1.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//6 18
		  -18.0, 0.1, -14.0,	0.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//5 19

		  //bottom
		  -18.0, -0.1, -14.0,	0.0f, 0.0f,			0.0f, -1.0f, 0.0f,		//4 20
		   18.0, -0.1, -14.0,	1.0f, 0.0f,			0.0f, -1.0f, 0.0f,		//7 21
		   18.0, -0.1,  0.0,	1.0f, 1.0f,			0.0f, -1.0f, 0.0f,		//1 22
		  -18.0, -0.1,  0.0,	0.0f, 1.0f,			0.0f, -1.0f, 0.0f,		//0 23
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
Mesh InitSecondPlatformMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	       Texture coords            Normals*/

		//front
		 -18.0, -0.1,  0.0,		0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//0 0
		  18.0, -0.1,  0.0,		1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//1 1
		  18.0,  0.1,  0.0,		1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//2 2
		 -18.0,  0.1,  0.0,		0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//3 3

		 //back	  
		 -18.0, -0.1, -4.0,		1.0f, 0.0f,				0.0f,  0.0f, -1.0f,//4 4
		 -18.0,  0.1, -4.0,		1.0f, 1.0f,				0.0f,  0.0f, -1.0f,//5 5
		  18.0,  0.1, -4.0,		0.0f, 1.0f,				0.0f,  0.0f, -1.0f,//6 6
		  18.0, -0.1, -4.0,		0.0f, 0.0f,				0.0f,  0.0f, -1.0f,//7 7

		  //left	  	  
		 -18.0, -0.1,  -4.0,	0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//4 8
		 -18.0,  0.1,  -4.0,	0.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//5 9
		 -18.0,  0.1,   0.0,	1.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//3 10
		 -18.0, -0.1,   0.0,	1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//0 11

		 //right   
		  18.0, -0.1,  0.0,		0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//1 12
		  18.0, -0.1, -4.0,		1.0f, 0.0f,				1.0f,  0.0f, 0.0f,	//7 13
		  18.0,  0.1, -4.0,		1.0f, 1.0f,				1.0f,  0.0f, 0.0f,	//6 14
		  18.0,  0.1,  0.0,		0.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//2 15

		  //top
		  -18.0,  0.1,  0.0,	0.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//3 16
		   18.0,  0.1,  0.0,	1.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//2 17
		   18.0,  0.1, -4.0,	1.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//6 18
		  -18.0,  0.1, -4.0,	0.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//5 19

		  //bottom		
		  -18.0, -0.1, -4.0,	0.0f, 0.0f,			0.0f, -1.0f, 0.0f,		//4 20
		   18.0, -0.1, -4.0,	1.0f, 0.0f,			0.0f, -1.0f, 0.0f,		//7 21
		   18.0, -0.1,  0.0,	1.0f, 1.0f,			0.0f, -1.0f, 0.0f,		//1 22
		  -18.0, -0.1,  0.0,	0.0f, 1.0f,			0.0f, -1.0f, 0.0f,		//0 23
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
Mesh InitStationSignMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	       Texture coords        Normals*/
	 -2.0f,  -0.5f, 0.0f,		0.0f, 0.0f, 	0.0f,  0.0f,  1.0f,//0
	  2.0f,  -0.5f, 0.0f,		1.0f, 0.0f, 	0.0f,  0.0f,  1.0f,//1
	  2.0f,   0.5f, 0.0f,		1.0f, 1.0f, 	0.0f,  0.0f,  1.0f,//2
	 -2.0f,   0.5f, 0.0f,		0.0f, 1.0f,  	0.0f,  0.0f,  1.0f,//3
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);
}

Mesh InitRailwayMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	           Texture coords               Normals*/
		 -18.0f,  -1.9f, 0.0f,		0.0f, 0.0f, 			0.0f,  1.0f, 0.0f,//0
		  18.0f,  -1.9f, 0.0f,		1.0f, 0.0f, 			0.0f,  1.0f, 0.0f,//1
		  18.0f,   1.9f, 0.0f,		1.0f, 1.0f, 			0.0f,  1.0f, 0.0f,//2
		 -18.0f,   1.9f, 0.0f,		0.0f, 1.0f,  			0.0f,  1.0f, 0.0f,//3
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);
}
Mesh InitTerrainMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		 18.0f,  0.8f,  4.0f,	0.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//3 16
		 22.0f,  0.8f,  4.0f,	1.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//2 17
		 22.0f,  0.8f,  0.0f,	1.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//6 18
		 18.0f,  0.8f,  0.0f,	0.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//5 19
	};

	std::vector<unsigned int> indices = {
		0,1,2,
		2,3,0
	};

	return Mesh(vertices, indices, texture);

}
//Mesh InitLightCubeMesh()
//{
//	std::vector<float> vertices =
//	{
//		/*Vertex coords	       Texture coords        Normals*/
//		 -1.0f,  0.0f,  1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//0
//		  1.0f,  0.0f,  1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//1  
//		  1.0f,  2.0f,  1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//2  
//		 -1.0f,  2.0f,  1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//3
//		 -1.0f,  0.0f, -1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//4
//		 -1.0f,  2.0f, -1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//5  
//		  1.0f,  2.0f, -1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//6  
//		  1.0f,  0.0f, -1.0f,      0.0f, 0.0f,   0.0f,  0.0f,  0.0f,//7
//	};
//
//	std::vector<unsigned int> indices =
//	{
//		0, 1, 2,//front
//		2, 3, 0,
//
//		4, 7, 6,//back
//		6, 5, 4,
//
//		3, 2, 6,//top
//		6, 5, 3,
//
//		0, 1, 7,//bottom
//		7, 4, 0,
//
//		0, 4, 5,//left side
//		5, 3, 0,
//
//		1, 7, 6,//right side
//		6, 2, 1
//	};
//
//	return Mesh(vertices, indices);
//}

enum Movement
{
	Reset,
	Move,
	Pause
};

enum LightAction
{
	Sunrise,
	Sunset
};

int main(void)
{
	/* Initializing the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Creating a window */
	float window_height = 850.0f, window_width = 1850.0f;
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

	//Loading shaders
	Shader object_shader("res/shaders/object.shader");//shader used for all objects
	object_shader.Bind();
	object_shader.SetUniform4f("u_LightColor", 1.0f, 1.0f, 1.0f, 1.0f);

	//Loading textures
	Texture station_platform_tex("res/textures/platform.jpg");

	Texture campina_station_tex("res/textures/brickss.jpg");
	Texture campina_station_roof_tex("res/textures/roof.jpg");
	Texture campina_station_door_tex("res/textures/door.jpg");
	Texture campina_station_windows_tex("res/textures/windows.jpg");
	Texture campina_station_left_window_tex("res/textures/left_windows.jpg");
	Texture campina_station_right_window_tex("res/textures/right_window.jpg");
	Texture campina_sign_tex("res/textures/campina.jpg");
	Texture bucuresti_station_tex("res/textures/bucuresti_station.png");
	Texture bucuresti_sign_tex("res/textures/bucuresti.jpg");
	Texture ploiesti_station_tex("res/textures/ploiesti_station.jpg");
	Texture ploiesti_sign_tex("res/textures/ploiesti.jpg");
	Texture brasov_station_tex("res/textures/brasov_station.png");
	Texture brasov_sign_tex("res/textures/brasov.jpg");
	Texture railway_tex("res/textures/railway.jpg");
	Texture bench_tex("res/textures/bench_1.jpg");
	Texture train_tex("res/textures/train.png");
	Texture grass_plain("res/textures/grass.png");
	Texture tree_1_tex("res/textures/tree_1.png");
	Texture rock_tex("res/textures/rock.png");
	Texture tree_2_tex("res/textures/tree_2.png");
	Texture tree_3_tex("res/textures/tree_3.png");


	// Initialize camera
	Camera camera(window_width, window_height, glm::vec3(0.0f, 5.0f, 10.0f));
	camera.SetPitch(-10.0f);
	float last_frame = 0.0f, delta_time;
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwSetCursorPos(window, (window_width / 2), (window_height / 2));

	Renderer renderer;

	glEnable(GL_DEPTH_TEST);

	Skybox skybox_scene;


	//Loading models from .obj
	std::vector<float> train_vertices;
	std::vector<unsigned int> train_indices;
	bool res = loadOBJ("res/models/train.obj", train_vertices, train_indices);

	std::vector<float> bench_vertices;
	std::vector<unsigned int> bench_indices;
	bool res2 = loadOBJ("res/models/bench_1.obj", bench_vertices, bench_indices);

	std::vector<float> tree_vertices;
	std::vector<unsigned int> tree_indices;
	bool res3 = loadOBJ("res/models/tree_1.obj", tree_vertices, tree_indices);

	std::vector<float> rock_vertices;
	std::vector<unsigned int> rock_indices;
	bool res4 = loadOBJ("res/models/rock.obj", rock_vertices, rock_indices);

	std::vector<float> tree2_vertices;
	std::vector<unsigned int> tree2_indices;
	bool res5 = loadOBJ("res/models/tree_2.obj", tree2_vertices, tree2_indices);

	std::vector<float> tree3_vertices;
	std::vector<unsigned int> tree3_indices;
	bool res6 = loadOBJ("res/models/tree_3.obj", tree3_vertices, tree3_indices);

	std::vector<float> bucuresti_vertices;
	std::vector<unsigned int> bucuresti_indices;
	bool res7 = loadOBJ("res/models/bucuresti.obj", bucuresti_vertices, bucuresti_indices);

	std::vector<float> ploiesti_vertices;
	std::vector<unsigned int> ploiesti_indices;
	bool res8 = loadOBJ("res/models/ploiesti.obj", ploiesti_vertices, ploiesti_indices);

	std::vector<float> brasov_vertices;
	std::vector<unsigned int> brasov_indices;
	bool res9 = loadOBJ("res/models/brasov.obj", brasov_vertices, brasov_indices);

	//Loading meshes
	Mesh campina_train_station = InitCampinaStationMesh(campina_station_tex);
	Mesh campina_train_station_roof = InitCampinaStationRoofMesh(campina_station_roof_tex);
	Mesh campina_train_station_door = InitCampinaDoorStationMesh(campina_station_door_tex);
	Mesh campina_station_main_windows = InitCampinaMainWindowsMesh(campina_station_windows_tex);
	Mesh campina_station_left_window = InitCampinaLeftWindowMesh(campina_station_left_window_tex);
	Mesh campina_station_right_window = InitCampinaRightWindowMesh(campina_station_right_window_tex);
	Mesh campina_station_sign = InitStationSignMesh(campina_sign_tex);

	Mesh main_platform = InitMainPlatformMesh(station_platform_tex);
	Mesh second_platform = InitSecondPlatformMesh(station_platform_tex);

	Mesh ploiesti_station_sign = InitStationSignMesh(ploiesti_sign_tex);
	Mesh ploiesti_station(ploiesti_vertices, ploiesti_indices, ploiesti_station_tex);

	Mesh brasov_station_sign = InitStationSignMesh(brasov_sign_tex);
	Mesh brasov_station(brasov_vertices, brasov_indices, brasov_station_tex);

	Mesh bucuresti_station_sign = InitStationSignMesh(bucuresti_sign_tex);
	Mesh bucuresti_station(bucuresti_vertices, bucuresti_indices, bucuresti_station_tex);

	Mesh railway = InitRailwayMesh(railway_tex);
	Mesh terrainPatch = InitTerrainMesh(grass_plain);
	//Mesh light_cube = InitLightCubeMesh();

	Mesh bench(bench_vertices, bench_indices, bench_tex);
	Mesh train(train_vertices, train_indices, train_tex);
	Mesh tree(tree_vertices, tree_indices, tree_1_tex);
	Mesh rock(rock_vertices, rock_indices, rock_tex);
	Mesh tree2(tree2_vertices, tree2_indices, tree_2_tex);
	Mesh tree3(tree3_vertices, tree3_indices, tree_3_tex);

	Terrain terrain;

	terrain.generatePositions(-600.0f, 600.0f, -100.0f, 100.0f);
	terrain.generateRailway(-600.0f, 600.0f);
	std::vector<std::pair<glm::vec3, int>>  terrainPos = terrain.getTerrainPositions();
	std::vector<glm::vec3> railwayPos = terrain.getRailway();

	Movement moveTrain = Movement::Reset;
	LightAction light_action = LightAction::Sunrise;

	float ambient_intensity = 0.7f;
	float diffuse = 0.2f;

	while (!glfwWindowShouldClose(window))
	{
		//Render here
		renderer.Clear();

		//Getting delta time
		float current_frame = static_cast<float>(glfwGetTime());
		delta_time = current_frame - last_frame;
		last_frame = current_frame;

		//Setting light
		{object_shader.Bind();
		object_shader.SetUniform1f("u_AmbientIntensity", ambient_intensity);
		object_shader.SetUniform1f("u_Diffuse", diffuse);
		object_shader.SetUniform3f("u_LightDirection", 0.0f, -30.0f, -20.0f);

		if (glfwGetKey(window, GLFW_KEY_L))
		{
			light_action = LightAction::Sunrise;
		}

		if (glfwGetKey(window, GLFW_KEY_N))
		{
			light_action = LightAction::Sunset;
		}

		switch (light_action)
		{
		case Sunrise:
		{
			if (ambient_intensity <= 0.7f)
			{
				ambient_intensity += 0.03f;
			}
			break;
		}
		case Sunset:
		{
			if (ambient_intensity > 0.3f)
			{
				ambient_intensity -= 0.03f;
			}
			break;
		}
		default:
			break;
		}
		}

		//Processing user input
		camera.ProcessInput(window, delta_time);

		//Rendering terrain with vegetation
		{
			for (auto& pos : terrainPos)
			{
				if (std::abs(camera.GetPosition().x - pos.first.x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - pos.first.z - 10.0f) < 80.0f)
				{
					if (pos.second == 1)
					{
						glm::vec3 treePos = pos.first;
						treePos.y = -0.1f;
						treePos.x = treePos.x + 20.0f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, treePos);
						model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));

						object_shader.Bind();
						object_shader.SetUniformMat4f("u_ViewMatrix", camera.GetViewMatrix());
						object_shader.SetUniformMat4f("u_ProjectionMatrix", camera.GetProjectionMatrix());
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						tree.Draw(camera, object_shader, renderer);
					}
					else if (pos.second == 2)
					{
						glm::vec3 rockPos = pos.first;
						rockPos.y = -0.1f;
						rockPos.x = rockPos.x + 20.0f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, rockPos);
						model = glm::scale(model, glm::vec3(0.80f, 0.8f, 0.8f));

						object_shader.Bind();
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						rock.Draw(camera, object_shader, renderer);
					}

					else if (pos.second == 3)
					{
						glm::vec3 treePos = pos.first;
						treePos.y = -0.1f;
						treePos.x = treePos.x + 20.0f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, treePos);
						model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));

						object_shader.Bind();
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						tree2.Draw(camera, object_shader, renderer);
					}
					else if (pos.second == 4)
					{
						glm::vec3 treePos = pos.first;
						treePos.y = -0.1f;
						treePos.x = treePos.x + 20.0f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, treePos);

						model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
						object_shader.Bind();
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						tree3.Draw(camera, object_shader, renderer);
					}


					glm::mat4 model = glm::mat4(1.0f);
					model = glm::translate(model, pos.first);

					object_shader.Bind();
					object_shader.SetUniformMat4f("u_ModelMatrix", model);

					terrainPatch.Draw(camera, object_shader, renderer);
				}
			}
		}

		//Rendering light cube
		/*{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, light_position);
			light_shader.Bind();
			light_shader.SetUniformMat4f("u_ModelMatrix", model);
			light_cube.Draw(camera, light_shader, renderer);
		}*/

		//Rendering train model
		{
			glm::mat4 model = glm::mat4(0.7f);

			//move train keys
			double fIncrement = 0.002;
			static double fMovementValue = 0.0;
			float current_x = glm::sin(fMovementValue) * 660.0f;

			if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
				moveTrain = Movement::Pause;

			if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
				moveTrain = Movement::Move;

			if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
				moveTrain = Movement::Reset;

			switch (moveTrain)
			{
			case Reset:
				break;
			case Move:
			{
				fMovementValue += fIncrement;
				model = glm::translate(model, glm::vec3(current_x, 0.0f, 0.0f));
				break;
			}
			case Pause:
			{
				model = glm::translate(model, glm::vec3(current_x, 0.0f, 0.0f));
				break;
			}
			default:
				break;
			}

			model = glm::translate(model, glm::vec3(0.0f, -0.09f, 7.4f));
			model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));

			object_shader.Bind();
			object_shader.SetUniformMat4f("u_ModelMatrix", model);

			train.Draw(camera, object_shader, renderer);
		}

		//Rendering railway
		{
			for (auto& pos : railwayPos)
			{
				if (std::abs(camera.GetPosition().x - pos.x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - pos.z - 10.0f) < 80.0f)
				{
					glm::mat4 model = glm::mat4(1.0f);
					model = glm::translate(model, pos);
					model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

					object_shader.Bind();
					object_shader.SetUniformMat4f("u_ModelMatrix", model);

					railway.Draw(camera, object_shader, renderer);
				}
			}
		}

		//Rendering Brasov first platform
		{
			if (std::abs(camera.GetPosition().x + 460.5f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-460.5f, 0.31f, 3.5f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				main_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Brasov second platform
		{
			if (std::abs(camera.GetPosition().x + 460.5f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-460.5f, 0.31f, 10.9f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				second_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Brasov train station building 
		{
			if (std::abs(camera.GetPosition().x + 460.5f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-460.5f, 0.38f, -2.0f));
				model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				brasov_station.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Brasov train station sign
		{
			if (std::abs(camera.GetPosition().x + 460.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-460.0f, 4.0f, 1.3f));
				model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				brasov_station_sign.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina train station building 
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_train_station.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina train station building roof 
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 5.0f, -0.5f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_train_station_roof.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina train station door
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.05f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_train_station_door.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina first front window
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-7.0f, 2.43f, 0.05f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_station_main_windows.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina second front window
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(7.0f, 2.43f, 0.05f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_station_main_windows.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina first left window
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -5.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_station_left_window.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina second left window
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -2.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_station_left_window.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina right window
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(11.52f, 2.6f, -3.5f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_station_right_window.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina train station sign
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 4.0f, 0.05f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				campina_station_sign.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina main platform
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 0.31f, 3.5f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				main_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina right bench model
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)

			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(8.5f, 0.5f, 1.3f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.38f, 0.38f, 0.38f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bench.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina left bench model
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)

			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-5.5f, 0.5f, 1.3f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.38f, 0.38f, 0.38f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bench.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina right side bench model
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)

			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(12.5f, 0.5f, -1.8f));
				model = glm::scale(model, glm::vec3(0.38f, 0.38f, 0.38f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bench.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Campina second platform
		{
			if (std::abs(camera.GetPosition().x - 10.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 0.31f, 10.9f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				second_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Ploiesti first platform
		{
			if (std::abs(camera.GetPosition().x - 210.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(210.0f, 0.31f, 3.5f));
				model = glm::scale(model, glm::vec3(0.8f, 0.8f, 1.2f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				main_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Ploiesti second platform
		{
			if (std::abs(camera.GetPosition().x - 210.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(210.0f, 0.31f, 10.9f));
				model = glm::scale(model, glm::vec3(0.8f, 0.8f, 1.0f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				second_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Ploiesti train station building 
		{
			if (std::abs(camera.GetPosition().x - 210.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(210.0f, 1.0f, -2.7f));
				model = glm::scale(model, glm::vec3(0.17f, 0.17f, 0.17f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				ploiesti_station.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Ploiesti train station sign
		{
			if (std::abs(camera.GetPosition().x - 207.5f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(207.5f, 4.5f, 1.47f));
				model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				ploiesti_station_sign.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Bucuresti first platform
		{
			if (std::abs(camera.GetPosition().x - 459.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(459.0f, 0.31f, 3.5f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				main_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Bucuresti second platform
		{
			if (std::abs(camera.GetPosition().x - 459.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(459.0f, 0.31f, 10.9f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				second_platform.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Bucuresti train station building 
		{
			if (std::abs(camera.GetPosition().x - 460.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(460.0f, -1.31f, -2.9f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bucuresti_station.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering Bucuresti train station sign
		{
			if (std::abs(camera.GetPosition().x - 459.0f) < 130.0f && std::abs(camera.GetPosition().z - 10.0f) < 80.0f)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(459.0f, 3.9f, -0.05f));
				model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bucuresti_station_sign.Draw(camera, object_shader, renderer);
			}
		}

		//Rendering skybox
		skybox_scene.Draw(camera.GetViewMatrix(), camera.GetProjectionMatrix());


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}