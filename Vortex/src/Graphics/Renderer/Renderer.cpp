#include "Renderer.h"

namespace vtx::gfx {
	Renderer::Renderer()
	{

	}

	void Renderer::Draw(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib)
	{
		va.Bind();
		vb.Bind();
		ib.Bind();
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::SetClearColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}
}