#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	default constructor.
	*/
	LinkedList();

	/**
	*	destructor.
	*/
	~LinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);

	void deleteitem(T& item);

	friend bool operator==(NodeType<T>& item0, T& item1);

	friend bool operator<(NodeType<T>& item0, T& item1);

	friend bool operator>(NodeType<T>& item0, T& item1);

	friend bool operator!=(NodeType<T>& item0, T& item1);

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}

//아이템 추가하는 에드 함수
template <typename T>
int LinkedList<T>::Add(T item)
{

	ResetList();

	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	node->data = item;
	node->next = NULL;

	if (!m_nLength)
	{
		m_pList = node;
	}
	else if (node->data <= m_pList->data)
	{
		node->next = m_pList;
		m_pList = node;
	}
	else
	{
		while (1)
		{
			pre = m_pCurPointer;
			GetNextItem(dummy);
			if (m_pCurPointer->next == NULL)
			{
				m_pCurPointer->next = node;
				//cout << "^^" << endl;
				break;
			}
			else if (node->data <= m_pCurPointer->next->data)
			{
				node->next = m_pCurPointer->next;
				m_pCurPointer->next = node;
				break;
			}
			// = pre->next;
			//break;
		}
	}
	m_nLength++;
	return 1;

}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);
	int a;

	while (moreToSearch && !found)
	{
		for (int i = 0; i < m_nLength; i++)
		{
			if (*location == item)
			{
				found = true;
				item = location->data;
				a = i;
			}
			else
			{
				location = location->next;
				moreToSearch = (location != NULL);
			}
		}

	}
	if (found && a != 0)
		return a;
	else if (found && a == 0)
		return -1;
	else
		return 0;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		//cout << "짠 " << m_pCurPointer << endl;
		m_pCurPointer = m_pList;
	}
	else {
		//cout << "뀨~" << m_pCurPointer << endl;
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;
	}
	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}

template <typename T>
bool operator==(NodeType<T>& item0, T& item1)
{
	return item0.data == item1;
}

template <typename T>
bool operator!=(NodeType<T>& item0, T& item1)
{
	return item0.data != item1;
}

template <typename T>
bool operator>(NodeType<T>& item0, NodeType<T>& item1)
{
	return item0.data > item1;
}

template <typename T>
bool operator<(NodeType<T>& item0, NodeType<T>& item1)
{
	return item0.data < item1;
}

template <typename T>
void LinkedList<T>::deleteitem(T& item)
{
	int a = 1;
	NodeType<T>* del;
	NodeType<T>* p;

	del = m_pList;
	if (m_pList == nullptr)
		return;

	else if (m_pList->data == item)
	{
		m_pList = m_pList->next;
	}
	else
	{
		p = del;
		if (del == NULL)
			return;
		else
		{
			p->next = del->next;
		}
		while (del != NULL && a < m_nLength - 1)
		{
			a++;

			del = del->next;
		}
	}
	m_nLength--;
}

#endif
