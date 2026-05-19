#pragma once

#include "ErrorHandle.h"

#include <vector>
#include <GLFW/glfw3.h>

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type) {
			case GL_FLOAT:
				return 4;
				break;
			case GL_UNSIGNED_INT:
				return 4;
				break;
			case GL_UNSIGNED_BYTE:
				return 1;
				break;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout {
public:
	VertexBufferLayout() :stride(0) {}

	template<typename T>
	void Push(unsigned int count) {
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count) {
		elements.push_back({ GL_FLOAT, count, GL_FALSE });
		stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement>& GetElements() const { return elements; }
	inline unsigned int GetStride() const { return stride; }
private:
	std::vector<VertexBufferElement> elements;
	unsigned int stride;
};