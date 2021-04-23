#pragma once

#include "..\..\Core\Core.h"
#include "..\..\Core\EssentialLibraries\DynamicArray.h"

namespace vtx::gfx
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static int GetSizeofType(unsigned int type)
		{
			if (type == GL_FLOAT)
				return 4;
			else if (type == GL_UNSIGNED_INT)
				return 4;
			else if (type == GL_UNSIGNED_BYTE)
				return 1;
			else
				return 0;
		}
	};

	class VORTEX_API VertexBufferLayout
	{
	private:
		DynamicArray<VertexBufferElement> mElements;
		unsigned int mStride;
	public:
		VertexBufferLayout()
			:mStride(0)
		{

		}

		template<typename T>
		void Push(unsigned int count)
		{
			static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			mElements.push_back({GL_FLOAT, count, GL_FALSE});
			mStride += (count * sizeof(float));
		}

		template<>
		void Push<unsigned int>(unsigned int count)
		{
			mElements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
			mStride += (count * sizeof(unsigned int));
		}

		template<>
		void Push<unsigned char>(unsigned int count)
		{
			mElements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
			mStride += (count * sizeof(unsigned char));
		}

		DynamicArray<VertexBufferElement> GetElements() { return mElements; }
		unsigned int GetStride() { return mStride; }
	};
}