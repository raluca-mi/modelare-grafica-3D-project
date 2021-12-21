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
	std::vector<glm::vec3> railway;
	
public:
	
	void generatePositions(float xStart, float xEnd, float zStart, float zEnd);
	void generateRailway(float start, float end);
	
	std::vector<std::pair<glm::vec3, int>>  getTerrainPositions() const;
	std::vector<glm::vec3> getRailway() const;

	int chooseTypeOfVegetation(int random);
};