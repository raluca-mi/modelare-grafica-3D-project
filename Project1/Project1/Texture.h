#pragma once

#include"Renderer.h"

class Texture
{
private:
	unsigned int m_RendererId;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:

	//Constructor
	Texture(const std::string& path);
	Texture(const Texture& texture);

	//Destructor
	~Texture();

	//Methods
	void Bind(unsigned int slot=0)const;
	void Unbind()const;

	//Getters
	inline int GetWidth() const { return m_Width; };
	inline int GetHeight() const { return m_Height; };

};

