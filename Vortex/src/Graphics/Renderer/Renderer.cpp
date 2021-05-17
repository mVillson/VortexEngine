#include "Renderer.h"

namespace vtx::gfx {
	Renderer::Renderer()
	{
		
	}

	void Renderer::Draw(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib, ShaderProgram& sp)
	{
		sp.Bind();

		static mat4 model(1.0), view(1.0), projection(1.0);

		model = mModel;

		view = mView;

		projection = mProjection;

		mat4 mvp = projection * view * model;
		sp.SetUniformMatrix("uMVP", mvp);

		va.Bind();
		vb.Bind();
		ib.Bind();

		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		sp.Unbind();
	}

	void Renderer::Draw(const VertexArray& va, const VertexBuffer& vb, ShaderProgram& sp, unsigned int count)
	{
		sp.Bind();

		static mat4 model(1.0), view(1.0), projection(1.0);

		model = mModel;

		view = mView;

		projection = mProjection;

		mat4 mvp = projection * view * model;
		sp.SetUniformMatrix("uMVP", mvp);

		va.Bind();
		vb.Bind();

		glDrawArrays(GL_TRIANGLES, 0, count);

		va.Unbind();
		vb.Unbind();
		sp.Unbind();
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::SetModel(mat4 m)
	{
		mModel = m;
	}

	void Renderer::SetView(mat4 m)
	{
		mView = m;
	}

	void Renderer::SetProjection(mat4 m)
	{
		mProjection = m;
	}

	void Renderer::SetClearColor(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
	}
}