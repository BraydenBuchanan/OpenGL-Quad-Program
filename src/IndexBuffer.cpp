#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : count(count) {
	GLCall(glGenBuffers(1, &rendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}