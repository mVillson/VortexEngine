#pragma once

#include "../../Core/Core.h"

#include <GL/glew.h>

namespace vtx::gfx {
	class VORTEX_API VertexBufferLayout
	{
	private:
		GLenum mType;
		int mComponents;
		int mSize;
		unsigned int mLocation;
	public:
		VertexBufferLayout(unsigned int location, int components, GLenum type, bool normalized = false);

		VertexBufferLayout();

		void Create(unsigned int location, int components, GLenum type, bool normalized = false);

		void Enable() const;
	};
}