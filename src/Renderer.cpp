#include "Renderer.h"

void Renderer::Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const {
	vertexArray.Bind();
	indexBuffer.Bind();
	shader.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
}