#pragma once
#include <string>
#include<vector>
#include"glm.hpp"
#include<fstream>
#include<iostream>

bool loadOBJ(std::string path, std::vector<float>& vbo, std::vector< unsigned int >& vertexIndices);

