#include "String.h"

namespace vtx {
	// Constructor
	String::String(const char* data)
		:mData(data)
	{

	}

	// Getter
	const char* String::c_str()
	{
		return mData;
	}
}