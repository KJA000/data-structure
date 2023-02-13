
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "HeapBase.h"
using namespace std;


#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application() {}

	/**
	*	destructor.
	*/
	~Application() {}

	void Run();
	void AddItem();
	void DisplayAllItem();
	int SearchItem();
	void Delete();
	int GetCommand();


	int m_Command;
};

#endif
