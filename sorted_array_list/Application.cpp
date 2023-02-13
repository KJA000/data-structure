#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:		// make empty list.
	        m_List.MakeEmpty();
			break;
		case 4:		// [�ۼ�] search item from list.
			int a;
			cout << "\t����Ž������ ã�� ���ϽŴٸ� 1��, �ƴ϶�� 2�� �Է��ϼ���." << endl;
			cout << "\t�Է� : ";
			cin >>  a;
			switch (a)
			{
			case 1:
				SearchItemByBinarySearch();
				continue;
			case 2:
				SearchItemById();
				continue;
			}
		case 5:
			RetriveRecordByMemberName();
			break;
		case 6:		// [�ۼ�] delete item from list
			DeleteItem();
			break;
		case 7:		// [�ۼ�] update item in list
			ReplaceItem();
			break;
		case 8:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 9:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item" << endl;
	cout << "\t   8 : Get from file" << endl; 
	cout << "\t   9 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	ItemType data;
	data.SetRecordFromKB();
	// [�ۼ�] �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (m_List.IsFull()) return 0;
    else m_List.Add(data);
	
	// [�ۼ�] ���� list ���
	DisplayAllItem();
	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	// [�ۼ�] list�� ��� �����͸� ȭ�鿡 ���
	ItemType data;

	cout << "\n\tCurrent list" << endl;
	m_List.ResetList();
	int index = m_List.GetNextItem(data);
	if (!m_List.GetLength()) cout  << "\tNothing" << endl;
	while (index < m_List.GetLength() && index != -1)
	{
		cout << "\t" << data.GetId() << ' ' << data.GetName() << ' ' << data.GetAddress() << endl;
		index = m_List.GetNextItem(data);
	}
	
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// [�ۼ�] ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (m_InFile.is_open()) return 0;
	else return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// [�ۼ�] ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (m_InFile.is_open()) return 0;
	else return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// [�ۼ�] file open, open error�� �߻��ϸ� 0�� ����
	m_InFile.open(filename);
	if (m_InFile.is_open() == 0) return 0;
	

	// [�ۼ�] ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		data.ReadDataFromFile(m_InFile);
		if (!m_List.IsFull())
		{
			m_List.Add(data);
		}
	}

	m_InFile.close();	// file close

	// [�ۼ�] ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// [�ۼ�] file open, open error�� �߻��ϸ� 0�� ����
	m_InFile.open(filename);
	if (m_InFile.is_open()==0) return 0;

	// [�ۼ�] list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// [�ۼ�] list�� ��� �����͸� ���Ͽ� ����
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		data.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchItemById() {
	ItemType temp;
	temp.SetIdFromKB();
	int a = m_List.Get(temp);
	if (a != 0)
	{
		return 1;
	}

	else
	{
		cout << "\t������ ����" << endl;
		return 0;
	}
	
}

int Application::DeleteItem() {

	ItemType data;
	data.SetIdFromKB();
	int n = m_List.Get(data);
	if (n)
	{
		m_List.Delete(data);
		DisplayAllItem();
		return 1;
	}
	else cout << "\t������ ����" << endl;
	return 0;
}

int Application::ReplaceItem()
{
	ItemType data;
	data.SetIdFromKB();
	int n = m_List.Get(data);
	if (n == 0) 
	{
		
		cout << "\t������ ����" << endl;
		return 0;
	}
	else
	{
		m_List.Replace(data);
		DisplayAllItem();
	}
	return 1;
}

int Application::SearchItemByBinarySearch()
{
	ItemType data;
	data.SetIdFromKB();
	m_List.GetBinarySearch(data);
	return 0;
}

int Application::RetriveRecordByMemberName()
{
	ItemType data;
	SearchListByMemberName(data);
	return 0;
}

int Application::SearchListByMemberName(ItemType& data)
{
	data.SetNameFromKB();
	int a = m_List.Get(data);
	if (a != 0)
	{
		return 1;
	}

	else
	{
		cout << "\t������ ����" << endl;
		return 0;
	}
}
