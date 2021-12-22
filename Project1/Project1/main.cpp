#include<GL/glew.h>
#include<glfw3.h>
#include<GL/glut.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "Mesh.h"

#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>

#include"OBJLoader.h";
#include "TextureSkybox.h"
#include"Terrain.h"


Mesh InitStationMesh(const Texture& texture)
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
Mesh InitStationRoofMesh(const Texture& texture)
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

		 -12.5,   -0.1,  -7.0,     0.0f,0.0f,        0.0f,  0.0f,  1.0f, //22
		-8.0,   -0.1,  -7.0,    1.0f, 0.0f,		  0.0f,  0.0f,  1.0f, //23
		-8.0,  2, -5.5,    1.0f, 1.0f,		  0.0f,  0.0f,  1.0f, //24

	   -8.0,    -0.1,   -7.0,    0.0f, 0.0f,		    0.0f,  0.0f,  1.0f,//25
	   -8.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  1.0f,//26
	   -4.0,    -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  1.0f,//27
	   -4.0,   2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  1.0f,//28

	   -4.0,    -0.1,   -7.0,    0.0f, 0.0f,			0.0f,  0.0f,  1.0f,//29
	   -4.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  1.0f,//30
	   0.0,     -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  1.0f,//31
	   0.0,    2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  1.0f,//32

	   0.0,    -0.1,   -7.0,    0.0f, 0.0f,			0.0f,  0.0f,  1.0f,//33
	   0.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  1.0f,//34
	   4.0,     -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  1.0f,//35
	   4.0,    2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  1.0f,//36

	   4.0,    -0.1,   -7.0,    0.0f, 0.0f,			0.0f,  0.0f,  1.0f,//37
	   4.0,   2,  -5.5,    0.0f, 1.0f,			0.0f,  0.0f,  1.0f,//38
	   8.0,     -0.1,   -7.0,    1.0f, 0.0f,			0.0f,  0.0f,  1.0f,//39
	   8.0,    2,  -5.5,    1.0f, 1.0f,			0.0f,  0.0f,  1.0f,//40

	  12.5,   -0.1,  -7.0,     0.0f,0.0f,            0.0f,  0.0f,  1.0f, //41
	   8.0,    -0.1,  -7.0,     1.0f, 0.0f,			0.0f,  0.0f,  1.0f, //42
	   8.0,   2,  -5.5,    1.0f, 1.0f,		    0.0f,  0.0f,  1.0f, //43

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
		-12.5, -0.1, -7.0,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//70
		-12.5, -0.1, -5.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//71
		-8.0,   2.0, -5.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//72

		-12.5, -0.1, -5.5,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//73
		-8.0,   2.0, -5.5,			1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//74
		-12.5, -0.1, -4.0,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//75
		-8.0,   2.0, -4.0,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//76

		-12.5, -0.1, -4.0,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//77
		-8.0,   2.0, -4.0,			1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//78
		-12.5, -0.1, -2.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//79
		-8.0,   2.0, -2.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//80

		-12.5, -0.1, -2.5,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//81
		-8.0,   2.0, -2.5,			1.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//82
		-12.5, -0.1, -0.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//83
		-8.0,   2.0, -0.5,			0.0f,  1.0f,		1.0f,  0.0f, 0.0f,		//84

		-12.5, -0.1,  1.0,			1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//67
		-12.5, -0.1, -0.5,			0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//68
		-8.0,   2.0, -0.5,			0.0f, 1.0f,		    1.0f,  0.0f, 0.0f,		//69

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
Mesh InitMainPlatformMesh(const Texture& texture)
{
	std::vector<float> vertices = {

		/*Vertex coords	       Texture coords            Normals*/

		//front
		 -18.0, -6.0,  0.0,		0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//0 0
		  18.0, -6.0,  0.0,		1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//1 1
		  18.0,  6.0,  0.0,		1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//2 2
		 -18.0,  6.0,  0.0,		0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//3 3

		 //back
		 -18.0, -6.0, -0.3,		1.0f, 0.0f,			0.0f,  0.0f, -1.0f,		//4 4
		 -18.0,  6.0, -0.3,		1.0f, 1.0f,			0.0f,  0.0f, -1.0f,		//5 5
		  18.0,  6.0, -0.3,		0.0f, 1.0f,			0.0f,  0.0f, -1.0f,		//6 6
		  18.0, -6.0, -0.3,		0.0f, 0.0f,			0.0f,  0.0f, -1.0f,		//7 7

		  //left	   	  
		 -18.0, -6.0,  -0.3,	0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//4 8
		 -18.0,  6.0,  -0.3,	0.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//5 9
		 -18.0,  6.0,   0.0,	1.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//3 10
		 -18.0, -6.0,   0.0,	1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//0 11

		 //right
		  18.0, -6.0,  0.0,		0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//1 12
		  18.0, -6.0, -0.3,		1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//7 13
		  18.0,  6.0, -0.3,		1.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//6 14
		  18.0,  6.0,  0.0,		0.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//2 15

		  //top
		  -18.0,  6.0,  0.0,	0.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//3 16
		   18.0,  6.0,  0.0,	1.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//2 17
		   18.0,  6.0, -0.3,	1.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//6 18
		  -18.0,  6.0, -0.3,	0.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//5 19

		  //bottom
		  -18.0, -6.0, -0.3,	0.0f, 0.0f,			0.0f,  -1.0f, 0.0f,		//4 20
		   18.0, -6.0, -0.3,	1.0f, 0.0f,			0.0f,  -1.0f, 0.0f,		//7 21
		   18.0, -6.0,  0.0,	1.0f, 1.0f,			0.0f,  -1.0f, 0.0f,		//1 22
		  -18.0, -6.0,  0.0,	0.0f, 1.0f,			0.0f,  -1.0f, 0.0f,		//0 23
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
		 -18.0, -0.8,  0.0,		0.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//0 0
		  18.0, -0.8,  0.0,		1.0f, 0.0f,			0.0f,  0.0f,  1.0f,		//1 1
		  18.0,  0.8,  0.0,		1.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//2 2
		 -18.0,  0.8,  0.0,		0.0f, 1.0f,			0.0f,  0.0f,  1.0f,		//3 3

		 //back
		 -18.0, -0.8, -0.3,		1.0f, 0.0f,			0.0f,  0.0f, -1.0f,		//4 4
		 -18.0,  0.8, -0.3,		1.0f, 1.0f,			0.0f,  0.0f, -1.0f,		//5 5
		  18.0,  0.8, -0.3,		0.0f, 1.0f,			0.0f,  0.0f, -1.0f,		//6 6
		  18.0, -0.8, -0.3,		0.0f, 0.0f,			0.0f,  0.0f, -1.0f,		//7 7

		  //left	   	  
		 -18.0, -0.8,  -0.3,	0.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//4 8
		 -18.0,  0.8,  -0.3,	0.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//5 9
		 -18.0,  0.8,   0.0,	1.0f, 1.0f,			-1.0f,  0.0f, 0.0f,		//3 10
		 -18.0, -0.8,   0.0,	1.0f, 0.0f,			-1.0f,  0.0f, 0.0f,		//0 11

		 //right
		  18.0, -0.8,  0.0,		0.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//1 12
		  18.0, -0.8, -0.3,		1.0f, 0.0f,			1.0f,  0.0f, 0.0f,		//7 13
		  18.0,  0.8, -0.3,		1.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//6 14
		  18.0,  0.8,  0.0,		0.0f, 1.0f,			1.0f,  0.0f, 0.0f,		//2 15

		  //top
		  -18.0,  0.8,  0.0,	0.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//3 16
		   18.0,  0.8,  0.0,	1.0f, 0.0f,			0.0f,  1.0f, 0.0f,		//2 17
		   18.0,  0.8, -0.3,	1.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//6 18
		  -18.0,  0.8, -0.3,	0.0f, 1.0f,			0.0f,  1.0f, 0.0f,		//5 19

		  //bottom
		  -18.0, -0.8, -0.3,	0.0f, 0.0f,			0.0f,  -1.0f, 0.0f,		//4 20
		   18.0, -0.8, -0.3,	1.0f, 0.0f,			0.0f,  -1.0f, 0.0f,		//7 21
		   18.0, -0.8,  0.0,	1.0f, 1.0f,			0.0f,  -1.0f, 0.0f,		//1 22
		  -18.0, -0.8,  0.0,	0.0f, 1.0f,			0.0f,  -1.0f, 0.0f,		//0 23
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
Mesh InitDoorStationMesh(const Texture& texture)
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
Mesh InitMainWindowsMesh(const Texture& texture)
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
Mesh InitLeftWindowMesh(const Texture& texture)
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
Mesh InitRightWindowMesh(const Texture& texture)
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
		 -18.0f,  -1.9f, 0.0f,		0.0f, 0.0f, 			0.0f,  -1.0f, 0.0f,//0
		  18.0f,  -1.9f, 0.0f,		1.0f, 0.0f, 			0.0f,  -1.0f, 0.0f,//1
		  18.0f,   1.9f, 0.0f,		1.0f, 1.0f, 			0.0f,  -1.0f, 0.0f,//2
		 -18.0f,   1.9f, 0.0f,		0.0f, 1.0f,  			0.0f,  -1.0f, 0.0f,//3
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

enum Movement
{
	Reset,
	Move,
	Pause
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

	//Set background color
	glClearColor(0.5f, 0.7f, 0.8f, 1.0f);

	//Set up the projection and view matrix
	glm::mat4 proj = glm::ortho(0.0f, window_width, 0.0f, window_height, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(0, 200, 0));
	
	//Loading shader (used for all objects)
	Shader object_shader("res/shaders/object.shader");
	object_shader.Bind();

	//Loading shader for cubemap
	Shader cubemap_shader("res/shaders/cubemap.shader");
	cubemap_shader.Bind();

	////Loading shader (used for light sources
	//object_shader.SetUniform4f("u_LightColor", 1.0f, 1.0f, 1.0f, 1.0f);
	//Shader light_shader("res\\shaders\\light.shader");

	//Loading textures
	Texture station_tex("res/textures/brickss.jpg");
	Texture station_roof_tex("res/textures/roof.jpg");
	Texture station_platform_tex("res/textures/platform.jpg");
	Texture station_door_tex("res/textures/door.jpg");
	Texture station_windows_tex("res/textures/windows.jpg");
	Texture station_left_window_tex("res/textures/left_windows.jpg");
	Texture station_right_window_tex("res/textures/right_window.jpg");
	Texture station_sign_tex("res/textures/sign.jpg");
	Texture railway_tex("res/textures/railway.jpg");
	Texture bench_texture("res/textures/bench_1.jpg");
	Texture train_texture("res/textures/train.png");
	Texture grassPlain("res/textures/grass.png");

	Texture tree_1("res/textures/tree_1.png");
	Texture rock_tex("res/textures/rock.png");
	Texture tree_2("res/textures/tree_2.png");
	Texture tree_3_tex("res/textures/tree_3.png");

	// Initialize camera
	Camera camera(window_width, window_height, glm::vec3(0.0f, 5.0f, 10.0f));
	camera.SetPitch(-10.0f);
	float last_frame = 0.0f, delta_time;
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwSetCursorPos(window, (window_width / 2), (window_height / 2));

	{
		Renderer renderer;

		glEnable(GL_DEPTH_TEST);

		//Loading train model from .obj
		std::vector<float> train_vertices;
		std::vector<unsigned int> train_indices;
		bool res = loadOBJ("res/models/train.obj", train_vertices, train_indices);

		//Loading bench model from .obj
		std::vector<float> bench_vertices;
		std::vector<unsigned int> bench_indices;
		bool res2 = loadOBJ("res/models/bench_1.obj", bench_vertices, bench_indices);

		//Loading tree_1 model from .obj
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

		//Loading meshes
		Mesh train_station = InitStationMesh(station_tex);
		Mesh train_station_roof = InitStationRoofMesh(station_roof_tex);
		Mesh main_platform = InitMainPlatformMesh(station_platform_tex);
		Mesh second_platform = InitSecondPlatformMesh(station_platform_tex);
		Mesh train_station_door = InitDoorStationMesh(station_door_tex);
		Mesh station_main_windows = InitMainWindowsMesh(station_windows_tex);
		Mesh station_left_window = InitLeftWindowMesh(station_left_window_tex);
		Mesh station_right_window = InitRightWindowMesh(station_right_window_tex);
		Mesh station_sign = InitStationSignMesh(station_sign_tex);
		Mesh railway = InitRailwayMesh(railway_tex);
		Mesh bench(bench_vertices, bench_indices, bench_texture);
		Mesh train(train_vertices, train_indices, train_texture);

		Mesh tree(tree_vertices, tree_indices, tree_1);
		Mesh terrainPatch = InitTerrainMesh(grassPlain);
		Mesh rock(rock_vertices, rock_indices, rock_tex);
		Mesh tree2(tree2_vertices, tree2_indices, tree_2);
		Mesh tree3(tree3_vertices, tree3_indices, tree_3_tex);

		float rot_angle = 0.0f;

		float skyboxVertices[] = {
			// positions          
			-500.0f, -500.0f, -500.0f,
			 500.0f, -500.0f, -500.0f,
			-500.0f,  500.0f, -500.0f,
			 500.0f, -500.0f, -500.0f,
			 500.0f,  500.0f, -500.0f,
			-500.0f,  500.0f, -500.0f,

			-500.0f, -500.0f,  500.0f,
			-500.0f, -500.0f, -500.0f,
			-500.0f,  500.0f, -500.0f,
			-500.0f,  500.0f, -500.0f,
			-500.0f,  500.0f,  500.0f,
			-500.0f, -500.0f,  500.0f,

			 500.0f, -500.0f, -500.0f,
			 500.0f, -500.0f,  500.0f,
			 500.0f,  500.0f,  500.0f,
			 500.0f,  500.0f,  500.0f,
			 500.0f,  500.0f, -500.0f,
			 500.0f, -500.0f, -500.0f,

			-500.0f, -500.0f,  500.0f,
			-500.0f,  500.0f,  500.0f,
			 500.0f,  500.0f,  500.0f,
			 500.0f,  500.0f,  500.0f,
			 500.0f, -500.0f,  500.0f,
			-500.0f, -500.0f,  500.0f,

			-500.0f,  500.0f, -500.0f,
			 500.0f,  500.0f, -500.0f,
			 500.0f,  500.0f,  500.0f,
			 500.0f,  500.0f,  500.0f,
			-500.0f,  500.0f,  500.0f,
			-500.0f,  500.0f, -500.0f,

			-500.0f, -500.0f, -500.0f,
			-500.0f, -500.0f,  500.0f,
			 500.0f, -500.0f, -500.0f,
			 500.0f, -500.0f, -500.0f,
			-500.0f, -500.0f,  500.0f,
			 500.0f, -500.0f,  500.0f
		};

		// Cubemap (Skybox)
		std::vector<std::string>faces;
		faces.push_back("res/skybox_1/right.jpg");
		faces.push_back("res/skybox_1/left.jpg");
		faces.push_back("res/skybox_1/top.jpg");
		faces.push_back("res/skybox_1/bottom.jpg");
		faces.push_back("res/skybox_1/back.jpg");
		faces.push_back("res/skybox_1/front.jpg");

		unsigned int cubemapTexture = TextureSkybox::loadCubemap(faces);

		// Setup skybox VAO
		unsigned int skyboxVAO, skyboxVBO;
		glGenVertexArrays(1, &skyboxVAO);
		glGenBuffers(1, &skyboxVBO);
		glBindVertexArray(skyboxVAO);
		glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);
		glBindVertexArray(0);


		Terrain terrain;
	
		terrain.generatePositions(-90.0f, 60.0f, -70.0f, 60.0f);
		terrain.generateRailway(-90.0f, 60.0f);
		std::vector<std::pair<glm::vec3, int>>  terrainPos = terrain.getTerrainPositions();
		std::vector<glm::vec3> railwayPos = terrain.getRailway();

		Movement moveTrain = Movement::Reset;

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

		
			//Draw terrain with vegetation
			{
				for (auto& pos : terrainPos)
				{
					if (pos.second == 1)
					{
						glm::vec3 treePos = pos.first;
						treePos.y = -0.1f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, treePos);
					
						model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
						object_shader.Bind();
						glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
						object_shader.SetUniformMat4f("u_VP", vp);
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						tree.Draw(camera, object_shader, renderer);


					}
					else if (pos.second == 2)
					{
						glm::vec3 rockPos = pos.first;
						rockPos.y = -0.1f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, rockPos);
						model = glm::scale(model, glm::vec3(0.80f, 0.8f, 0.8f));
						object_shader.Bind();
						glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
						object_shader.SetUniformMat4f("u_VP", vp);
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						rock.Draw(camera, object_shader, renderer);
					}
					else if (pos.second == -1)
					{
						glm::mat4 model = glm::mat4(1.0f);
						glm::vec3 railwayPos = pos.first;
						railwayPos.y = -0.01f;
						railwayPos.z = 5.1f;

						model = glm::translate(model, railwayPos);
						model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

						object_shader.Bind();
						glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
						object_shader.SetUniformMat4f("u_VP", vp);
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						railway.Draw(camera, object_shader, renderer);
						
					}
					else if (pos.second == 3)
					{
						glm::vec3 treePos = pos.first;
						treePos.y = -0.1f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, treePos);

						model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
						object_shader.Bind();
						glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
						object_shader.SetUniformMat4f("u_VP", vp);
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						tree2.Draw(camera, object_shader, renderer);
					}
					else if (pos.second == 4)
					{
						glm::vec3 treePos = pos.first;
						treePos.y = -0.1f;
						glm::mat4 model = glm::mat4(1.0f);
						model = glm::translate(model, treePos);

						model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
						object_shader.Bind();
						glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
						object_shader.SetUniformMat4f("u_VP", vp);
						object_shader.SetUniformMat4f("u_ModelMatrix", model);

						tree3.Draw(camera, object_shader, renderer);
					}
					
					glm::mat4 model = glm::mat4(1.0f);
					model = glm::translate(model, pos.first);
					object_shader.Bind();
					glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
					object_shader.SetUniformMat4f("u_VP", vp);
					object_shader.SetUniformMat4f("u_ModelMatrix", model);

					terrainPatch.Draw(camera, object_shader, renderer);
				}

			}


			//Draw right bench model
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(8.5f, 0.5f, 1.3f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.38f, 0.38f, 0.38f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bench.Draw(camera, object_shader, renderer);
			}

			//Draw left bench model
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-5.5f, 0.5f, 1.3f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.38f, 0.38f, 0.38f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bench.Draw(camera, object_shader, renderer);
			}

			//Draw right side bench model
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(12.5f, 0.5f, -1.8f));
				model = glm::scale(model, glm::vec3(0.38f, 0.38f, 0.38f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				bench.Draw(camera, object_shader, renderer);
			}

			//Draw train model
			{
				glm::mat4 model = glm::mat4(0.7f);

				//move train keys
				double fIncrement = 0.0002;
				static double fMovementValue = 0.0;
				float current_x = glm::sin(fMovementValue) * 480.0f;

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

				model = glm::translate(model, glm::vec3(0.0f, -0.09f, 5.1f));
				model = glm::rotate(model, glm::radians(360.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				train.Draw(camera, object_shader, renderer);
			}

			//Draw train station building
			{
				glm::mat4 model = glm::mat4(1.0f);

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				train_station.Draw(camera, object_shader, renderer);
			}

			//Draw train station building roof 
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 5.0f, -0.5f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				train_station_roof.Draw(camera, object_shader, renderer);
			}

			//Draw train station door
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.05f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				train_station_door.Draw(camera, object_shader, renderer);
			}

			//Draw first front window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-7.0f, 2.43f, 0.05f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				station_main_windows.Draw(camera, object_shader, renderer);
			}

			//Draw second front window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(7.0f, 2.43f, 0.05f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				station_main_windows.Draw(camera, object_shader, renderer);
			}

			//Draw first left window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -5.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				station_left_window.Draw(camera, object_shader, renderer);
			}

			//Draw second left window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -2.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				station_left_window.Draw(camera, object_shader, renderer);
			}

			//Draw right window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(11.52f, 2.6f, -3.5f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				station_right_window.Draw(camera, object_shader, renderer);
			}

			//Draw train station sign
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 4.0f, 0.05f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				station_sign.Draw(camera, object_shader, renderer);
			}

			//Draw main platform
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, -2.8f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				main_platform.Draw(camera, object_shader, renderer);
			}


			//Draw railway
			{
				for (auto& pos : railwayPos)
				{
					glm::mat4 model = glm::mat4(1.0f);
					model = glm::translate(model, pos);
					model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

					object_shader.Bind();
					glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
					object_shader.SetUniformMat4f("u_VP", vp);
					object_shader.SetUniformMat4f("u_ModelMatrix", model);

					railway.Draw(camera, object_shader, renderer);
				}
			}

			//Draw second platform
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 7.8f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

				object_shader.Bind();
				glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
				object_shader.SetUniformMat4f("u_VP", vp);
				object_shader.SetUniformMat4f("u_ModelMatrix", model);

				second_platform.Draw(camera, object_shader, renderer);
			}


			//Draw skybox as last
			glm::mat4 model = glm::mat4(1.0f);
			glDepthFunc(GL_LEQUAL);
			cubemap_shader.Bind();

			glm::mat4 vp = camera.GetProjectionMatrix() * camera.GetViewMatrix();
			cubemap_shader.SetUniformMat4f("u_VP", vp);
			cubemap_shader.SetUniformMat4f("u_ModelMatrix", model);

			glBindVertexArray(skyboxVAO);
			glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			glDepthFunc(GL_LESS);
			glDepthFunc(GL_LEQUAL);


			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}