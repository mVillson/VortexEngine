#pragma once

#include "..\Core.h"

namespace vtx {
	class VORTEX_API String
	{
	private:
		const char* mData;
	public:
		// Constructor
		String(const char* data);

		// Getter
		const char* c_str();
	};
}