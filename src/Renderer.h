#pragma once

#include <GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
public:
	Renderer(const Renderer&) = delete;

	static Renderer& Get() {
		static Renderer instance;
		return instance;
	}

	static void Result(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) { Get().Clear(), Get().Draw(vertexArray, indexBuffer, shader); }
private:
	void Clear() const { GLCall(glClear(GL_COLOR_BUFFER_BIT)); }
	void Draw(const VertexArray& vertexArray, const IndexBuffer& indexbuffer, const Shader& shader) const;
	Renderer() {}
};