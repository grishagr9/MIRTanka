#pragma once

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

GLuint shaderProgram;

GLint attribVertex;

GLint attribTex;

GLint attribNormal;

GLint unifTexture;

GLint unifRotate;
GLint unifMove;
GLint unifScale;

GLuint roadVBO;
GLuint busVBO;
GLuint grassVBO;
GLuint skyVBO;
GLuint treeVBO;


GLint roadTextureHandle;
GLint busTextureHandle;
GLint grassTextureHandle;
GLint skyTextureHandle;
GLint treeTextureHandle;


sf::Texture roadTextureData;
sf::Texture busTextureData;
sf::Texture grassTextureData;
sf::Texture skyTextureData;
sf::Texture treeTextureData;


GLuint roadVAO;
GLuint busVAO;
GLuint grassVAO;
GLuint skyVAO;
GLuint treeVAO;


GLint Unif_transform_viewPosition;

GLint Unif_material_emission;
GLint Unif_material_ambient;
GLint Unif_material_diffuse;
GLint Unif_material_specular;
GLint Unif_material_shininess;

GLint Unif_light_ambient;
GLint Unif_light_diffuse;
GLint Unif_light_specular;
GLint Unif_light_attenuation;
GLint Unif_light_direction;