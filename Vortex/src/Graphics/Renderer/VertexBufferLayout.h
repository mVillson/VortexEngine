#pragma once

#include "..\..\Core\Core.h"
#include "..\..\Core\EssentialLibraries\DynamicArray.h"

namespace vtx::gfx
{
	struct VertexBufferElement
	{
		GLenum type;
		GLint count;
		GLubyte normalized;
	};

	class VORTEX_API VertexBufferLayout
	{
	private:
		DynamicArray<VertexBufferElement> mElements;

		int mStride = 0;
		int mOffset = 0;
		int mLayoutID = 0;
	public:
		VertexBufferLayout()
		{

		}

		template<typename T>
		void Create(GLint count)
		{
			static_assert(false);
		}

		template<>
		void Create<float>(GLint count)
		{
			mElements.push_back({GL_FLOAT, count, GL_FALSE});

			mStride += count * sizeof(float);

			glVertexAttribPointer(mLayoutID, mElements.get(mLayoutID + 1).count, mElements.get(mLayoutID + 1).type, mElements.get(mLayoutID + 1).normalized, mStride, (const void*)mOffset);
			glEnableVertexAttribArray(mLayoutID);

			mOffset += (sizeof(float) * count);

			mLayoutID++;
		}
	};
}