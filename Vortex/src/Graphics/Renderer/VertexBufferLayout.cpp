#include "VertexBufferLayout.h"

namespace vtx::gfx {
	VertexBufferLayout::VertexBufferLayout(unsigned int location, int components, GLenum type, bool normalized)
		:mLocation(location), mType(type), mComponents(components), mSize(0)
	{
		if (type == GL_FLOAT)
			mSize = sizeof(GL_FLOAT);

		glVertexAttribPointer(location, mComponents, mType, normalized, mSize * mComponents, 0);
	}

	VertexBufferLayout::VertexBufferLayout()
		:mLocation(0), mType(0), mComponents(0), mSize(0)
	{

	}

	void VertexBufferLayout::Create(unsigned int location, int components, GLenum type, bool normalized)
	{
		mLocation = location;
		mType = type;
		mComponents = components;
		mSize = 0;

		if (type == GL_FLOAT)
			mSize = sizeof(GL_FLOAT);

		glVertexAttribPointer(location, mComponents, mType, normalized, mSize * mComponents, 0);
	}

	void VertexBufferLayout::Enable() const
	{
		glEnableVertexAttribArray(mLocation);
	}
}