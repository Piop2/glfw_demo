#if !defined(OPENGLDEMO_RENDERING_MESHLOADER_H)
#define OPENGLDEMO_RENDERING_MESHLOADER_H

#include <vector>

#include "draw_details.hpp"
#include "vertex.hpp"

DrawDetails UploadMesh(
    const std::vector<Vertex>& mesh,
    const std::vector<GLuint> elem
);

DrawDetails UploadMesh(
    const GLfloat* verts,
    const GLfloat* colors,
    const int v_count, 
	const GLuint* elems,
    const int e_count
);

void UnloadMesh(std::vector<DrawDetails>& details);

#endif // OPENGLDEMO_RENDERING_MESHLOADER_H
