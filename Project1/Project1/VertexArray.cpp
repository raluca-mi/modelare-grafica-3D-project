#include "VertexArray.h"
#include"VertexBufferLayout.h"

#include"Renderer.h"

#pragma once

//Constructor
VertexArray::VertexArray()
{
	GlCall(glGenVertexArrays(1, &m_RendererID));
}

//Destructor
VertexArray::~VertexArray()
{
	GlCall(glDeleteVertexArrays(1, &m_RendererID));
}

//Methods
void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int index = 0; index < elements.size(); index++)
	{
		const auto& element = elements[index];
		GlCall(glEnableVertexAttribArray(index));
		GlCall(glVertexAttribPointer(index, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count*VertexBufferElement::GetSizeOfType(element.type);
	}
	
}

void VertexArray::Bind() const
{
	GlCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GlCall(glBindVertexArray(0));
}
