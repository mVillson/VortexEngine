#pragma once

#include "../../Core/Core.h"

#include <GL/glew.h>

namespace vtx::gfx {

	class VORTEX_API VertexBuffer
	{
	private:
		GLuint mVbo;
	public:
		VertexBuffer(const void* data, unsigned int size);
		VertexBuffer();
		~VertexBuffer();

		void Create(const void* data, unsigned int size);

		void Bind() const;
		void Unbind() const;
	};

	class VORTEX_API IndexBuffer
	{
	private:
		GLuint mIbo;
		unsigned int mCount;
	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		IndexBuffer();
		~IndexBuffer();

		void Create(const unsigned int* data, unsigned int count);

		inline unsigned int GetCount() const;

		void Bind() const;
		void Unbind() const;
	};

}
