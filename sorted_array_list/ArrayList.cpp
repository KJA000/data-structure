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
	for (int i = 0; i < m_Length; i++)
	{
		if (data.GetId() == m_Array[i].GetId()||data.GetName()==m_Array[i].GetName()) {
			cout << '\n' << "------------아이템 발견------------" << '\n' << endl;
			m_Array[i].DisplayRecordOnScreen();
			
			if (i != 0)
				return i;
			else if (i == 0)
				return -1;
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
	ItemType* temp;
	temp = m_Array;
	if(!IsFull())
	{
		if (m_Length == 0)
		{
			m_Array[m_Length] = inData;
			m_Length++;
		}
		else
		{
			if (m_Array[0].GetId() > inData.GetId())
			{
				for (int i = 0; i < m_Length; i++)
				{
					m_Array[0] = inData;
					m_Array[i + 1] = temp[i];
				}
				m_Length++;
			}
			else if (m_Array[m_Length - 1].GetId() < inData.GetId())
			{
				m_Array[m_Length] = inData;
				m_Length++;
			}
			else
			{
				for (int i = 0; i < m_Length; i++)
				{	
					if ((m_Array[i].GetId() <= inData.GetId()) && (m_Array[i + 1].GetId() >= inData.GetId()))
					{
						temp = new ItemType[m_Length - i - 1];
						for (int j = 0; j < m_Length - i - 1; j++)
						{
							temp[j] = m_Array[i + j + 1];
							m_Array[i + 1] = inData;
							m_Array[i + j + 2] = temp[j];
						}
					}
				}
				m_Length++;
				//delete [] temp;
			}
		}
	}
	return 0;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}

int ArrayList::Replace(ItemType data) 
{
	ItemType inData;
	int a;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (data.GetId()==m_Array[i].GetId())
		{
			Delete(m_Array[i]);
			cout << "\t----------바꿀 데이터 입력---------" << endl;
			inData.SetRecordFromKB();
			a = Get(m_Array[i]);
			Add(inData);
			return 1;
		}
	}
	return 0;
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

int ArrayList::Delete(ItemType data)
{
	//if (Get(data))
	//{
		for (int i = 0; i < MAXSIZE; i++)
		{
			if (data.GetId() == m_Array[i].GetId())
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
		return 0;
}
int ArrayList::GetBinarySearch(ItemType& data)
{
	int row = 0;
	int high = GetLength() - 1;
	int mid;
	while (row <= high)
	{
		mid = (row + high) / 2;
		if (m_Array[mid].GetId() == data.GetId())
		{
			cout << '\n' << "------------아이템 발견------------" << '\n' << endl;
			m_Array[mid].DisplayRecordOnScreen();
			return 1;
		}
		else if (m_Array[mid].GetId() > data.GetId())
			high = mid - 1;
		else
			row = mid + 1;
	}
	cout << "\t데이터 없음" << endl;
	return 0;
}
