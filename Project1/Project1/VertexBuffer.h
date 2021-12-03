#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererID;
public:

	//Constructor
	VertexBuffer(const void* data, unsigned int size);

	//Destructor
	~VertexBuffer();

	//Methods
	void Bind()const;
	void Unbind()const;

};

