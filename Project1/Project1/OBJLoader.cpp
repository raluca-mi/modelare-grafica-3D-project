#include"OBJLoader.h";
#include <unordered_set>

bool loadOBJ(std::string path, std::vector<float>& vbo, std::vector< unsigned int >& vertexIndices)
{
	
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;
	std::vector<float> vertexBuffer;

	//to improve performance,not used yet
	std::unordered_set<size_t> processedVertices;

	std::size_t verticesCount = 0;

	std::ifstream read(path);
	if (!read.is_open())
	{
		std::cout << "Imposible to open file";
		return false;
	}

	while (true)
	{
		std::string line;
		read >> line;
		if (line=="end")
		{
			break;
		}
		if (line == "v")
		{
			glm::vec3 vertex;
			read >> vertex.x >> vertex.y >> vertex.z;
			temp_vertices.push_back(vertex);
			++verticesCount;
		}
		else if (line == "vt")
		{
			glm::vec2 uv;
			read >> uv.x >> uv.y;
			temp_uvs.push_back(uv);
		}
		else if (line == "vn")
		{
			glm::vec3 normal;
			read >> normal.x >> normal.y >> normal.z;
			temp_normals.push_back(normal);
		}
		else if (line == "f")
		{
			char slash;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			
			read >> vertexIndex[0]>> slash>> uvIndex[0] >> slash >> normalIndex[0]  >> vertexIndex[1] >> slash >> uvIndex[1] >> slash >> normalIndex[1]  >> vertexIndex[2] >> slash >> uvIndex[2] >> slash >> normalIndex[2];

			vertexIndices.push_back(vertexIndex[0]-1);
			vertexIndices.push_back(vertexIndex[1]-1);
			vertexIndices.push_back(vertexIndex[2]-1);

			
		}
	}

	for (size_t i = 0; i < verticesCount; i++)
	{
		vbo.push_back(temp_vertices[i].x);
		vbo.push_back(temp_vertices[i].y);
		vbo.push_back(temp_vertices[i].z);
		vbo.push_back(temp_uvs[i].x);
		vbo.push_back(temp_uvs[i].y);
	}
	

}