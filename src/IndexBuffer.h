#pragma once

#include "ErrorHandle.h"

class IndexBuffer {
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer() { GLCall(glDeleteBuffers(1, &rendererID)); }

	void Bind() const { GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID)); }
	void Unbind() const { GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); }

	inline unsigned int GetCount() const { return count; }
private:
	unsigned int rendererID;
	unsigned int count;
};