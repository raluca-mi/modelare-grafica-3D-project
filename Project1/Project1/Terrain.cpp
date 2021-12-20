#include"Terrain.h"



void Terrain::generatePositions(float xStart, float xEnd, float zStart, float zEnd)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6);
	for (float x = xStart; x <= xEnd; x += 4.0f)
	{
		for (float z = zStart; z <= zEnd; z += 4.0f)
		{
			glm::vec3 pos = { x,-0.9f,z };
			std::pair<glm::vec3, int> sector = std::make_pair(pos, dist6(rng));
			if (z>=0.0f && z<=4.0f)
			{
				sector.second = -1;
			}
			else if (z >= -10.0f && z <= 10.0f)
			{
				sector.second = 0;
			}
			terrainPos.push_back(sector);
		}
	}
}


std::vector<std::pair<glm::vec3, int>>  Terrain::getTerrainPositions() const
{
	return terrainPos;
}


