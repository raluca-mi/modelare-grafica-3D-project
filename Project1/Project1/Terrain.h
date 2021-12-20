#include <vector>
#include <glm.hpp>
#include"Camera.h"
#include"Renderer.h"
#include"Shader.h"
#include"Mesh.h"
#include<random>

class Terrain
{
	std::vector<std::pair<glm::vec3,int>> terrainPos;
	
public:
	
	void generatePositions(float xStart, float xEnd, float zStart, float zEnd);
	
	std::vector<std::pair<glm::vec3, int>>  getTerrainPositions() const;
	
};