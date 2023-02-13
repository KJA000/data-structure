#include "Application.h"

template <typename T>
void Application<T>::Run()
{
	while (1)
	{
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand)
		{
		case 1:		// inset item
			InsertItem();
			break;
		case 2:		// retrieves item
			DisplayAll();
			break;
		case 3:
			RetrieveItem();
			break;
		case 0:	// quit
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}

template <typename T>
int Application<T>::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Insert Item" << endl;
	cout << "\t   2 : Display all Item" << endl;
	cout << "\t   3 : Retrieve Item" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

template <typename T>
int Application<T>::InsertItem()
{
	T item;

	cout << "Input Item : ";
	cin >> item;

	m_List.Add(item);
	DisplayAll();

	return 1;
}

template <typename T>
void Application<T>::DisplayAll()
{
	T data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		cout << data << " - ";
	}
}



// Retrieve item in the list.
template <typename T>
int Application<T>::RetrieveItem()
{
	T item;
	cout << "Enter a item for search : ";
	cin >> item;

	if (m_List.Get(item))
	{
		cout << "Target item exists in the list." << endl;
		return 1;
	}
	else
	{
		cout << "Target item is not in the list." << endl;
		return 0;
	}
}

template <typename T>
int Application<T>::DeleteItem()
{
	T item;
	cout << "\t ������ ������ �Է� : ";
	cin >> item;
	if (!m_List.Get(item)) cout << "\t����Ʈ�� ������ ����" << endl;
	else
	{
		m_List.deleteitem(item);
		DisplayAll();
	}
	return 0;
}

template <typename T>
int Application<T>::MakeEmpty()
{
	m_List.MakeEmpty();
	return 0;
}
