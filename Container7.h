#ifndef _CONTAINER_7_H_
#define	_CONTAINER_7_H_

#include "Account7.h";

template <typename T>
class Container
{
private:
	T* arr;
	int length;
	int aIndex;
public:
	Container(int len=50);
	~Container();
	void Insert(T data);
	T Remove(int idx);

	T GetItem(int idx);
	int GetElementSum() {return aIndex;}
};

template <typename T>
Container<T> :: Container(int len) : aIndex(0)
{
	if(len < 50)
		len = 50;

	length = len;
	arr = new Element[length];
}

template <typename T>
Container<T> :: ~Container()
{
	delete [] arr;
}

template <typename T>
void Container<T> :: Insert(T data)
{
	if(aIndex > length)
		cout << "데이터 초과!!" << endl;
	else
		arr[aIndex++] = data;
}

template <typename T>
T Container<T> :: Remove(int idx)
{
	if(idx < 0 || idx >= aIndex)
	{
		cout << "더 이상 뺄 수 없다!" << endl;
		return NULL;
	}
	else	
	{
		T del = arr[idx];

		for(int i = idx; i < aIndex - 1; i++)
		{
			arr[i] = arr[i+1];
		}
		aIndex--;

		return del;
	}
}

template <typename T>
T Container<T> :: GetItem(int idx)
{
	if(idx < 0 || idx >= aIndex)
	{
		cout << "더 이상 뺄 수 없다!" << endl;
		return NULL;
	}
	return arr[idx];
}

#endif