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
		case 4:		// [작성] search item from list.
			SearchData();
			break;
		case 5:		// [작성] delete item from list
			DeleteItem();
			break;
		case 6:		// [작성] update item in list
			UpdateItem();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
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
	cout << "\t   4 : Search item" << endl;
	cout << "\t   5 : Delete item" << endl;
	cout << "\t   6 : Update item" << endl;
	cout << "\t   7 : Get from file" << endl; 
	cout << "\t   8 : Put to file " << endl; 
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
	// [작성] 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_List.IsFull()) return 0;
    else m_List.Add(data);
	
	// [작성] 현재 list 출력
	DisplayAllItem();
	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	// [작성] list의 모든 데이터를 화면에 출력
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
	
	// [작성] 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (m_InFile.is_open()) return 0;
	else return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// [작성] 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (m_InFile.is_open()) return 0;
	else return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// [작성] file open, open error가 발생하면 0을 리턴
	m_InFile.open(filename);
	if (m_InFile.is_open() == 0) return 0;
	

	// [작성] 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		data.ReadDataFromFile(m_InFile);
		if (!m_List.IsFull())
		{
			m_List.Add(data);
		}
	}

	m_InFile.close();	// file close

	// [작성] 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// [작성] file open, open error가 발생하면 0을 리턴
	m_InFile.open(filename);
	if (m_InFile.is_open()==0) return 0;

	// [작성] list 포인터를 초기화
	m_List.ResetList();

	// [작성] list의 모든 데이터를 파일에 쓰기
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		data.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchData() {
	ItemType temp;
	int a = m_List.Get(temp);
	if (a!=-1&&a!=0)
	{
		cout << "\t" << "리스트 위치 : " << a << endl;
		return 1;
	}

	if (a == -1) 
	{
		cout << "\t리스트 위치 : 0" << endl;
		return 1;
	}
	else
	{
		cout << "\t데이터 없음" << endl; 
		return 0;
	}
	
}

int Application::DeleteItem() {

	ItemType data;
	//data.SetRecordFromKB();
	int n = m_List.Get(data);
	if (n)
	{
		m_List.Delete(data);
		return 1;
	}
	else cout << "\t데이터 없음" << endl;
	return 0;
}

int Application::UpdateItem()
{
	ItemType data;
	//data.SetRecordFromKB();
	int n = m_List.Get(data);
	if (n == 0) 
	{
		cout << "\t데이터 없음" << endl;
		return 0;
	}
	else
	{
		m_List.Replace(data);
		DisplayAllItem();
	}
	return 1;
}