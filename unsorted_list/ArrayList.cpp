#include "ArrayList.h"


// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}

int ArrayList::Get(ItemType& data)
{
	int index;
	data.SetRecordFromKB();
	for (int i = 0; i < m_Length; i++)
	{
		if (data.GetAddress() == m_Array[i].GetAddress() && data.GetId() == m_Array[i].GetId() && data.GetName() == m_Array[i].GetName()) {
			data = m_Array[i];
			index = i;
			//cout << index;
			if (i == 0) return -1;
			else return index;
		}
	}
	return 0;
}

// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}

void ArrayList::Replace(ItemType data) 
{
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (data.GetAddress() == m_Array[i].GetAddress() && data.GetId() == m_Array[i].GetId() && data.GetName() == m_Array[i].GetName())
			{
				cout << "\t----------바꿀 데이터 입력---------" << endl;
				m_Array[i].SetRecordFromKB();
			}
		}
}

// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

void ArrayList::Delete(ItemType data)
{
	//if (Get(data))
	//{
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (data.GetAddress() == m_Array[i].GetAddress() && data.GetId() == m_Array[i].GetId() && data.GetName() == m_Array[i].GetName())
			{
				if (i == MAXSIZE - 1)
				{
					m_Length--;
				}
				else
				{
					for (int j = 0; j < MAXSIZE; j++)
					{
						m_Array[i] = m_Array[i + 1];
					}
					m_Length--;
				}
			}
		}
	//}
}