
#ifndef _HEAPBASE_H
#define _HEAPBASE_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;
#define MAXSIZE 10;
#include "ItemType.h"



template <typename T>
struct HeapType {
	T data;

};

template <typename T>
class HeapBase
{
public:
	HeapBase();
	virtual ~HeapBase();

	bool IsEmpty();
	bool IsFull();

	int GetLength() const;
	void MakeEmpty();
	virtual int Add(T item);
	virtual int Delete(T item);
	virtual T pop();

	virtual void RetrieveItem(T& item, bool& found);
	virtual void PrintHeap();

	virtual void ReheapDown(int iperent, int ibottom) = 0;
	virtual void ReheapUp(int iroot, int ibottom) = 0;
	virtual void Delte(T item, bool& found, int iparent) = 0;
	virtual void Retrieve(T& item, bool& found, int iparent) = 0;

protected:
	T* m_pHeap;
	int m_iLastNode;
	int m_nMaxSize;
	int m_nLength;
};

template <typename T>
int HeapBase<T>::Delete(T item)
{
	return 0;
}

template <typename T>
T HeapBase<T>::pop()
{
	return;
}

template <typename T>
int HeapBase<T>::Add(T item)
{
	return 1;
}

template <typename T>
bool HeapBase<T>::IsEmpty()
{
	if (m_iLastNode == -1) return 1;
	else return 0;
}

template <typename T>
bool HeapBase<T>::IsFull()
{
	return 0;
}

template <typename T>
int HeapBase<T>::GetLength() const
{
	return m_nLength;
}

template <typename T>
void HeapBase<T>::MakeEmpty()
{
	
}

template <typename T>
HeapBase<T>::HeapBase()
{
	m_nMaxSize = MAXSIZE;

	m_pHeap = new T[m_nMaxSize];
	m_iLastNode = -1;
}
template <typename T>
HeapBase<T>::~HeapBase()
{
	delete[] m_pHeap;
}
template <typename T>
void HeapBase<T>::RetrieveItem(T& item, bool& found)
{
	
}

template <typename T>
void HeapBase<T>::PrintHeap()
{

}
#endif	