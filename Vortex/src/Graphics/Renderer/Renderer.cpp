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

	void Renderer::DrawQuad(float bottom_left_x, float bottom_left_y, float top_right_x, float top_right_y, ShaderProgram& sp)
	{
		float vertices[] =
		{
			bottom_left_x, bottom_left_y, 0.0f, 0.0f, 0.0f, // bottom left
			bottom_left_x, top_right_y, 0.0f, 0.0f, 1.0f,   // top left
			top_right_x, top_right_y, 0.0f, 1.0f, 1.0f,     // top right
			top_right_x, bottom_left_y, 0.0f, 1.0f, 0.0f    // bottom right
		};

		unsigned int indices[] =
		{
			0, 1, 2,
			2, 3, 0
		};

		VertexArray vao;
		VertexBuffer vbo;
		IndexBuffer ibo;

		VertexBufferLayout layout;

		vao.Create();

		vbo.Create(vertices, sizeof(vertices));

		ibo.Create(indices, 6);

		layout.Push<float>(3);
		layout.Push<float>(2);
		vao.AddBuffer(vbo, layout);

		sp.Bind();
		vao.Bind();
		ibo.Bind();
		vbo.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
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