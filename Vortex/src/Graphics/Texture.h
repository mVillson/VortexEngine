#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include "..\Vendor\stb_image\stb_image.h"

#include "GraphicsCore.h"

#include <string>
#include <fstream>

namespace vtx::gfx {
	class VORTEX_API Texture
	{
	private:
		unsigned int mRendererID;
		const char* mFilepath;
		unsigned char* mLocalBuffer;
		int mWidth, mHeight, mBPP;
	public:
		Texture(const char* filepath);
		Texture();
		~Texture();

		void Create(const char* filepath);

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
	};
}