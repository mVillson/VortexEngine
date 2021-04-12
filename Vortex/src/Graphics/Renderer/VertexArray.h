#pragma once

#include "..\..\Core\Core.h"

#include "Buffer.h"
#include "VertexBufferLayout.h"

#include <GL\glew.h>

namespace vtx::gfx {

	class VORTEX_API VertexArray 
	{
	private:
		GLuint mVao;
	public:
		VertexArray();
		~VertexArray();

		void Create();

		void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

		void Bind() const;
		void Unbind() const;

	};
}