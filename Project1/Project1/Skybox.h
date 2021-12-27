#pragma once

#include <GL/glew.h>
#include <vector>
#include <stb_image.h>

#include "Renderer.h"

class Skybox
{
public:
    Skybox();
    ~Skybox();

    void Draw(const glm::mat4& view, const glm::mat4& projection);

private:
    unsigned int cubemapTexture;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    Shader skybox_shader;

    GLuint loadCubemap(std::vector<std::string> faces);
};
