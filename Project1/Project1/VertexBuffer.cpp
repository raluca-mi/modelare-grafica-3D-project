#include "VertexBuffer.h"

#include"Renderer.h"

#pragma once

//Constructor
VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GlCall(glGenBuffers(1, &m_RendererID));
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	GlCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

//Destructor
VertexBuffer::~VertexBuffer()
{
	GlCall(glDeleteBuffers(1, &m_RendererID));
}

//Methods
void VertexBuffer::Bind()const
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind()const
{
	GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
