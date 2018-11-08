#include <iostream>
#include "ArrayBase.h"
using namespace std;


void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int len = strlen(number);

	char* newNum = nullptr;

	for (int i = 0; i < len; ++i)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
			//当找到非零字符时，直接从当前地址打印字符串即可，无需printf每个字符
			newNum = number + i;
			break;
		}
	}

	if(newNum!=nullptr)
		cout << newNum << " ";
}

//递归的打印1到N位最大数
void Print1ToMaxNRecusively(char* number, int length, int index)
{

	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = '0' + i;
		Print1ToMaxNRecusively(number, length, index + 1);
	}
}


void Print1ToMaxN(int n)
{
	if (n < 0)
		return ;

	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxNRecusively(number, n, 0);
	}

	delete[] number;

}


bool isEven(int n)
{
	return (n & 1) == 0;
}


void Reorder(int* pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length <= 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;

		while (pBegin < pEnd && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}

}



int main()
{
	ArrayBase* array = new palindromeArray();
	int data[5] = { 1,0,1,1,1 };
	array->setData(data, 5);

	int min = array->Min();
	cout << min<<endl;


	delete array;

	Print1ToMaxN(2);
	cout << endl;

	cout << endl;
	int num[5] = { 1,2,3,4,5 };
	Reorder(num, 5, isEven);

	//delete data;
	unsigned int cnt = 0;
	int n = 32;
	for (int i = 1; i <= n; i *= 2)
		for (int j = (i / 2); j <=i; j++)
			cout << j << " ";

	cout << endl;

	int(*a)[5] = { 0 };
	*a[1] = 0;

	int *b[5] = { 0, 0,0,0,0 };

	system("pause");
	return 0;
}