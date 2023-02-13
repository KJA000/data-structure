#include "Application.h"

// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// ����Ʈ�� �������� �߰��Ѵ�.
			AddItem();
			break;
		case 2:		// ��ũ���� ����Ʈ�� ��� ������ ������ ����Ѵ�.
			Delete();
			break;
		case 3:		// ����Ʈ�� ����.
			DisplayAllItem();
			break;
		case 4:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�´�.
			SearchItem();
			break;

		case 0:		// ���α׷��� ������.
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

