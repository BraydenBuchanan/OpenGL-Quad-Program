#pragma once

#include "ErrorHandle.h"

class VertexBuffer {
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer() { GLCall(glDeleteBuffers(1, &rendererID)); }

	void Bind() const { GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID)); }
	void Unbind() const { GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); }
private:
	unsigned int rendererID;
};