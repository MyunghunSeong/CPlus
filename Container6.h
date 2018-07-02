#ifndef _CONTAINER_6_H_
#define	_CONTAINER_6_H_

#include "Account6.h";

typedef Account* Element;

class Container
{
private:
	Element* arr;
	int length;
	int aIndex;
public:
	Container(int len=50);
	~Container();
	void Insert(Element data);
	Element Remove(int idx);

	Element GetItem(int idx);
	int GetElementSum() {return aIndex;}
};

#endif