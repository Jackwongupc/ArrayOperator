#include"ArrayBase.h"
#include<exception>

/**************************palindromeArray**********************/
palindromeArray::palindromeArray()
{

}


palindromeArray::~palindromeArray()
{

}


int palindromeArray::Min()
{
	if (m_data == nullptr || m_length <= 0)
		throw new std::exception("Invalid parameters!");

	int index1 = 0;
	int index2 = m_length - 1;
	int indexMid = index1;

	while (m_data[index1] >= m_data[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		//如果下标为index1、index2、indexMid的数字相等，只能采用顺序查找
		if (m_data[index1] == m_data[index2] && m_data[index1] == m_data[indexMid])
			return MinInorder(index1, index2);

		if (m_data[indexMid] >= m_data[index1])
			index1 = indexMid;
		else if (m_data[indexMid] <= m_data[index2])
			index2 = indexMid;

	}

	return m_data[indexMid];
}

int palindromeArray::MinInorder(int index1, int index2)
{
	int result = m_data[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (result > m_data[i])
			result = m_data[i];
	}

	return result;
}