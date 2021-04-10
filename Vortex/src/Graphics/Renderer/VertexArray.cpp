#include "VertexArray.h"

namespace vtx::gfx {

	VertexArray::VertexArray()
		:mVao(0)
	{
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &mVao);
	}

	void VertexArray::Create()
	{
		glGenVertexArrays(1, &mVao);
		glBindVertexArray(1);
	}

	void VertexArray::AddBuffer(const VertexBuffer& vb)
	{
		Bind();
		vb.Bind();

		/*
		const auto& elements = layout.GetElements();

		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
			glEnableVertexAttribArray(i);
			offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		}
		*/
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(1);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

}