#pragma once

#include "..\GraphicsCore.h"

#include "VertexArray.h"
#include "Buffer.h"
#include "ShaderProgram.h"

namespace vtx::gfx {
	class VORTEX_API Renderer
	{
	private:
	public:
		Renderer();
		void Draw(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib, const ShaderProgram& sp);
		void SetClearColor(float red, float green, float blue, float alpha);
	};
}
