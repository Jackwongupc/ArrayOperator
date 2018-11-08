#pragma once

class ArrayBase
{
public:
	ArrayBase()
	{

	}

	~ArrayBase()
	{
		if (m_data != nullptr)
		{
			//delete[] m_data;
		}
	}

	void setData(int* data, int length)
	{
		m_data = data;
		m_length = length;

	}

	virtual int Min()
	{
		return 0;
	}

protected:
	int* m_data = nullptr;
	int m_length = 0;
};


class palindromeArray : public ArrayBase
{
public:
	palindromeArray();

	~palindromeArray();

	virtual int Min();

	int MinInorder(int index1, int index2);
};