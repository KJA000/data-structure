#include "ItemType.h"
#include <iostream>
using namespace std;

#define maxQueue 10


/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	Queue class.
*	@details	This class processes as First In, First Out (FIFO), 템플릿을 적용해 다양한 변수 타입을 저장할 수 있다.
*/
template <typename T>
class CircularQueueType
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueueType();


	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront와 m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void EnQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
};

template <typename T>
CircularQueueType<T>::CircularQueueType()
{
	m_pItems = new ItemType[maxQueue];
	m_iFront = 0;
	m_iRear = 0;
	m_nMaxQueue = maxQueue;
}

template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] m_pItems;
}

template <typename T>
CircularQueueType<T>::CircularQueueType(int max)
{
	m_nMaxQueue = max;
	m_iFront = 0;
	m_iRear = 0;
	m_pItems = new ItemType[max];
}

template <typename T>
bool CircularQueueType<T>::IsEmpty()
{
	//cout << "프론트 : " << m_iFront << " 리어 : " << m_iRear << endl;
	if (m_iFront == m_iRear) return 1;
	return 0;
}

template <typename T>
bool CircularQueueType<T>::IsFull()
{
	return ((m_iRear + 1) % m_nMaxQueue) == m_iFront;
}

template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iRear = 0;
	m_iFront = 0;
}

template <typename T>
void CircularQueueType<T>::EnQueue(T item)
{
	if (IsFull())
	{
		throw FullQueue();
	}
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;
}

template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
	if (IsEmpty())
	{
		throw EmptyQueue();
	}
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];
}

template <typename T>
void CircularQueueType<T>::Print()
{
	int f = m_iFront + 1, r = m_iRear;


	if (m_iFront <= m_iRear)
	{
		while (f <= r)
		{
			cout << "\t" << m_pItems[f];
			f++;
		}
	}
	else {
		while (f <= m_nMaxQueue - 1)
		{
			cout << m_pItems[f + 1] << ' ';
			f++;
		}
		f = 0;
		while (f <= r) {
			cout << m_pItems[f + 1];
			f++;
		}
	}

	/*
	if (!IsEmpty()) {
		for (int i = 1; i < m_nMaxQueue; i++)
		{
			cout << "\t" << m_pItems[i] << ' ';
		}
		cout << endl;
	}*/
}


