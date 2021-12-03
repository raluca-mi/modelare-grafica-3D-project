#pragma once

#include"VertexBuffer.h"

class VertexBufferLayout;

class VertexArray
{
private:
	unsigned int m_RendererID;

public:

	//Constructor
	VertexArray();

	//Destructor
	~VertexArray();

	//Methods
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind()const;

};

