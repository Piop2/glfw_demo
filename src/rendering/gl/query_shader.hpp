#if !defined(OPENGLDEMO_RENDERING_QUERYSHADER_H)
#define OPENGLDEMO_RENDERING_QUERYSHADER_H

#include <cstdio>

#include <iostream>
#include <vector>

#include <glad/glad.h>

const char* getTypeString(GLenum type);

void QueryInputAttribs(GLuint handle);

void QueryUniforms(GLuint handle);

#endif // OPENGLDEMO_RENDERING_QUERYSHADER_H
