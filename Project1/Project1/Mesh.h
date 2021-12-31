#pragma once
#include<GL/glew.h>
#include<glfw3.h>

#include<vector>

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

class Mesh
{
	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indices;
	Texture m_texture;

	VertexArray m_vertex_array;
	VertexBuffer m_vertex_buffer;
	IndexBuffer m_index_buffer;

public:
	Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const Texture& texture = Texture());
	Mesh(const Mesh& mesh);

	void SetTexture(const Texture& texture);

	//draws the mesh
	void Draw(const Camera& camera, Shader& shader, const Renderer& renderer);
};