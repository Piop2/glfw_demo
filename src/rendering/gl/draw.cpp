#include "rendering/gl/draw.hpp"

#include <vector>

#include "rendering/gl/draw_details.hpp"

void Draw(const std::vector<DrawDetails>& details)
{
	for (const auto& d : details)
	{
		glBindVertexArray(d.vao);
		glDrawElements(GL_TRIANGLES, d.num_elements, GL_UNSIGNED_INT, nullptr);
	}
	glBindVertexArray(0);
}