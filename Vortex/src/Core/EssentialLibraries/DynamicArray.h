#pragma once

template<typename ty>
class __declspec(dllexport) DynamicArray
{
private:
	int mSize = 0;
	ty* mArray;
	ty* mTempArray = nullptr;
public:
	// allocates the mArray member
	DynamicArray()
	{
		mArray = new ty[mSize];
	}

	// deletes both mArray and mTempArray members
	~DynamicArray()
	{
		mArray = nullptr;
		delete mArray;

		mArray = nullptr;
		delete mArray;
	}

	// push data to the array
	void push_back(ty data)
	{
		mSize++;

		mTempArray = new ty[mSize];
		for (int i = 0; i < mSize; i++)
		{
			mTempArray[i] = mArray[i];
		}

		mArray = new ty[mSize];

		for (int i = 0; i < mSize; i++)
		{
			mArray[i] = mTempArray[i];
		}

		mArray[mSize] = data;
	}

	// pops the last pushed data from the array
	void pop_back()
	{
		mTempArray = new ty[mSize];
		for (int i = 0; i < mSize; i++)
		{
			mTempArray[i] = mArray[i];
		}

		mArray = new ty[mSize];

		for (int i = 0; i < mSize; i++)
		{
			mArray[i] = mTempArray[i];
		}

		mSize--;
	}

	// get the value at the specified location
	ty get(unsigned int location) const
	{
		return mArray[location];
	}

	// returns the size of the array
	int size() const
	{
		return mSize;
	}
};