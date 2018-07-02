#include <iostream>
#include "Container6.h"

using namespace std;

Container :: Container(int len) : aIndex(0)
{
	if(len < 50)
		len = 50;

	length = len;
	arr = new Element[length];
}

Container :: ~Container()
{
	delete [] arr;
}

void Container :: Insert(Element data)
{
	if(aIndex > length)
		cout << "데이터 초과!!" << endl;
	else
		arr[aIndex++] = data;
}

Element Container :: Remove(int idx)
{
	if(idx < 0 || idx >= aIndex)
	{
		cout << "더 이상 뺄 수 없다!" << endl;
		return NULL;
	}
	else	
	{
		Element del = arr[idx];

		for(int i = idx; i < aIndex - 1; i++)
		{
			arr[i] = arr[i+1];
		}
		aIndex--;

		return del;
	}
}

Element Container :: GetItem(int idx)
{
	if(idx < 0 || idx >= aIndex)
	{
		cout << "더 이상 뺄 수 없다!" << endl;
		return NULL;
	}
	return arr[idx];
}