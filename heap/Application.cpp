#include "Application.h"

// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 리스트에 아이템을 추가한다.
			AddItem();
			break;
		case 2:		// 스크린에 리스트의 모든 아이템 정보를 출력한다.
			Delete();
			break;
		case 3:		// 리스트를 비운다.
			DisplayAllItem();
			break;
		case 4:		// ID를 이용하여 리스트에서 아이템을 찾는다.
			SearchItem();
			break;

		case 0:		// 프로그램을 끝낸다.
			return;

		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}

int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Display item" << endl;
	cout << "\t   4 : Search item" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::AddItem()
{

}

void Application::DisplayAllItem()
{

}
int Application::SearchItem()
{
	return 0;
}
void Application::Delete()
{

}

