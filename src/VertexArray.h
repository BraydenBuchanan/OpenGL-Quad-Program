#pragma once

#include "VertexBuffer.h"
#include "ErrorHandle.h"

class VertexBufferLayout;

class VertexArray {
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
private:
	unsigned int rendererID;
};