#pragma once

#include "..\GraphicsCore.h"

#include "Buffer.h"
#include "VertexBufferLayout.h"

namespace vtx::gfx {

	class VORTEX_API VertexArray 
	{
	private:
		GLuint mVao;
	public:
		VertexArray();
		~VertexArray();

		void Create();

		void Bind() const;
		void Unbind() const;
	};
}