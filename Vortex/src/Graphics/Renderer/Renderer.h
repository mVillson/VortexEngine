#pragma once

#include "..\GraphicsCore.h"

#include "VertexArray.h"
#include "Buffer.h"
#include "ShaderProgram.h"

namespace vtx::gfx {
	class Renderer
	{
	private:
		mat4 mModel;
		mat4 mView;
		mat4 mProjection;

	public:
		VORTEX_API Renderer();
		void VORTEX_API Draw(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib, ShaderProgram& sp);
		void VORTEX_API Draw(const VertexArray& va, const VertexBuffer& vb, ShaderProgram& sp, unsigned int count);

		void VORTEX_API DrawQuad(float bottom_left_x, float bottom_left_y, float top_right_x, float top_right_y, ShaderProgram& sp);

		void VORTEX_API Clear();

		void VORTEX_API SetModel(mat4 m);
		void VORTEX_API SetView(mat4 m);
		void VORTEX_API SetProjection(mat4 m);

		mat4 VORTEX_API GetModel() { return mat4(1.0); }
		
		void VORTEX_API SetClearColor(float red, float green, float blue, float alpha);
	};
}
