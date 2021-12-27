#include"Terrain.h"



void Terrain::generatePositions(float xStart, float xEnd, float zStart, float zEnd)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 15);
	for (float x = xStart; x <= xEnd; x += 4.0f)
	{
		for (float z = zStart; z <= zEnd; z += 4.0f)
		{
			glm::vec3 pos = { x,-0.9f,z };
			std::pair<glm::vec3, int> sector = std::make_pair(pos, chooseTypeOfVegetation(dist(rng)));

		    if (z >= -15.0f && z <= 15.0f && x>=-40.f && x<=0.f)
			{
				sector.second = 0;
			}
			else if (z >= -15.0f && z <= 15.0f && x >= 175.f && x <= 205.f)
			{
				sector.second = 0;
			}
			else if (z >= -15.0f && z <= 15.0f && x >= 415.f && x <= 455.f)
			{
				sector.second = 0;
			}
			 else if (z >= -1.f && z <= 8.f)
			 {
				 sector.second = 0;
			 }
			terrainPos.push_back(sector);
		}
	}
}

void Terrain::generateRailway(float start, float end)
{
	for (float x = start; x <= end; x += 36.0f)
	{
		railway.push_back({ x,-0.01f,5.1f });
	}
}


std::vector<std::pair<glm::vec3, int>>  Terrain::getTerrainPositions() const
{
	return terrainPos;
}

std::vector<glm::vec3> Terrain::getRailway() const
{
	return railway;
}

int Terrain::chooseTypeOfVegetation(int random)
{
	if (random >= 1 && random <= 3)
	{
		return 1;
	}
	if (random > 3 && random < 6)
	{
		return 3;
	}
	if (random >= 6 && random <= 7)
	{
		return 4;
	}
	if (random == 10)
	{
		return 2;
	}
	return random;
}


