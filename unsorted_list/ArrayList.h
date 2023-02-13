#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList()	{}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(ItemType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized. 
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(ItemType& data);

	/** [작성]
	*	@brief	리스트에서의 위치 포인터를 1증가, 만약 리스트의 끝부분이면 -1리턴, 아니면 포인터 리턴 
	*	@pre 없음
	*	@post	리스트에서의 위치 포인터를 1증가, 만약 리스트의 끝부분이면 -1리턴, 아니면 포인터 리턴. 파라메터로 받은 데이터를 배열의 해당 위치값에 있는 값으로 바꿈
	*	@param 입력 받은 데이터
	*	@return 포안터가 리스트 끝부분이면 -1, 리스트의 현재 포인터 위치를 라턴
	*/
	int Get(ItemType& data);

	/** [작성]
	*	@brief 해당 데이터가 있으면 위치 리턴, 없으면 0 리턴
	*	@pre 없음
	*	@post 받은 데이터의 주소, 이름, 아이디가 현재 리스트의 값과 일치하면 해당 인덱스를 리턴함
	*	@param 입력 받은 데이터
	*	@return 해당 데이터가 있으면 위치를 리턴한다 다만 만약 위치가 0번째라면 -1을 리턴, 없을 경우에 0을 리턴함
	*/
	void Delete(ItemType data);

	/** [작성]
	*	@brief 데이터 받아서 삭제함
	*	@pre Get 이용해서 데이터 있는지 확인
	*	@post 해당 데이터가 삭제됨, 리스트 전체 길이도 한칸 작아짐 i가 4면 맨 끝이므로 1 빼주고 끝, 그러나 4가 아닐 경우 나머지 원소들 다 한칸식 옮겨줌
	*	@param 아이템타입형 데이터. 데이터 입력받은 값을 파라메터로 함
	*	@return 없음
	*/
	void Replace(ItemType data);

private:
	ItemType m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H