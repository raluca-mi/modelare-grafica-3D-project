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
	Shader object_shader("res/shaders/object.shader");
	object_shader.Bind();

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

	Texture train_texture("res/textures/train.png");

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
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
		bool res = loadOBJ("res/models/train.obj", vertices, indices);

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
		
		Mesh train(vertices, indices, train_texture);

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
				model = glm::translate(model, glm::vec3(0.0f, -0.09f, 5.1f));
				model = glm::rotate(model, glm::radians(360.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				train.Draw(camera, object_shader, renderer);
			}

			//Draw train station building
			{
				glm::mat4 model = glm::mat4(1.0f);
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				train_station.Draw(camera, object_shader, renderer);
			}

			//Draw train station building roof 
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 5.0f, -0.5f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				train_station_roof.Draw(camera, object_shader, renderer);
			}

			//Draw train station door
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				train_station_door.Draw(camera, object_shader, renderer);
			}

			//Draw first front window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-7.0f, 2.43f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				station_main_windows.Draw(camera, object_shader, renderer);
			}

			//Draw second front window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(7.0f, 2.43f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				station_main_windows.Draw(camera, object_shader, renderer);
			}

			//Draw first left window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -5.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				station_left_window.Draw(camera, object_shader, renderer);
			}

			//Draw second left window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(-11.52f, 3.0f, -2.0f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				station_left_window.Draw(camera, object_shader, renderer);
			}

			//Draw right window
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(11.52f, 2.6f, -3.5f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				station_right_window.Draw(camera, object_shader, renderer);
			}

			//Draw train station sign
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, 4.0f, 0.05f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				station_sign.Draw(camera, object_shader, renderer);
			}

			//Draw main platform
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, -2.8f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				main_platform.Draw(camera, object_shader, renderer);
			}


			//Draw railway
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 5.1f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				railway.Draw(camera, object_shader, renderer);
			}

			//Draw second platform
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, glm::vec3(0.0f, -0.01f, 7.8f));
				model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
				glm::mat4 mvp = camera.GetProjectionMatrix() * camera.GetViewMatrix() * model;

				object_shader.Bind();
				object_shader.SetUniformMat4f("u_MVP", mvp);

				second_platform.Draw(camera, object_shader, renderer);
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