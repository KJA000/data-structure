#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;
#define MAXSIZE 10;
#include "ItemType.h"
#include "HeapBase.h"

template <typename T>
class MaxHeap : public HeapBase<T>
{
public:
	MaxHeap() {}
	MaxHeap(int size)
	{
		size = 0;
	}

	virtual void ReheapDown(int iperent, int ibottom);
	virtual void ReheapUp(int iroot, int ibottom);
	virtual void Delte(T item, bool& found, int iparent);
	virtual void Retrieve(T& item, bool& found, int iparent);

};


#endif