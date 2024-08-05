#if !defined(OPENGL_RENDERING_GL_DRAWDETAILS_H)
#define OPENGL_RENDERING_GL_DRAWDETAILS_H

#include <glad/glad.h>

struct DrawDetails
{
	GLuint vao = 0;
	GLuint num_elements = 0;

	DrawDetails(GLuint v, GLuint e)
    {
        vao = v;
        num_elements = e;
    }
};


#endif // OPENGL_RENDERING_GL_DRAWDETAILS_H
