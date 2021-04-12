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

	void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
	{
		Bind();
		vb.Bind();
		layout.Enable();
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