#pragma once

#include <GL/glew.h>

#include "..\..\Core\Core.h"

#include "Buffer.h"
#include "VertexArray.h"

namespace vtx::gfx {
	class VORTEX_API Renderer
	{
	private:
	public:
		Renderer();
		void Draw(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib);
		void SetClearColor(float red, float green, float blue, float alpha);
	};
}
