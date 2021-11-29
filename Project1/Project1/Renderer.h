#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexArray.h"


#define ASSERT(x) if (!(x)) __debugbreak();
#define GlCall(x) GlClearError();\
		x;\
		ASSERT(GlLogCall(#x, __FILE__,__LINE__))

void GlClearError();
bool GlLogCall(const char* function, const char* file, int line);


class Renderer
{
public:
	void Clear()const ;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};


