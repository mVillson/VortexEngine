#include "Buffer.h"

namespace vtx::gfx {

	// ---------------------------------------------------------------------------------
	// VertexBuffer
	// ---------------------------------------------------------------------------------
	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		glGenBuffers(1, &mVbo);
		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	VertexBuffer::VertexBuffer()
		:mVbo(0)
	{

	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &mVbo);
	}

	void VertexBuffer::Create(const void* data, unsigned int size)
	{
		glGenBuffers(1, &mVbo);
		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, mVbo);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// ---------------------------------------------------------------------------------
	// IndexBuffer
	// ---------------------------------------------------------------------------------
	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
		:mCount(count)
	{
		glGenBuffers(1, &mIbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mCount * sizeof(GLuint), data, GL_STATIC_DRAW);
	}

	IndexBuffer::IndexBuffer()
		:mCount(0), mIbo(0)
	{

	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &mIbo);
	}

	void IndexBuffer::Create(const unsigned int* data, unsigned int count)
	{
		mCount = count;

		glGenBuffers(1, &mIbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mCount * sizeof(GLuint), data, GL_STATIC_DRAW);
	}

	inline unsigned int IndexBuffer::GetCount() const
	{
		return mCount;
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}