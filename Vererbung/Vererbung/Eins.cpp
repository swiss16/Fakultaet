#include "stdafx.h"
#include "Eins.h"
#include <iostream>
#include <conio.h>

using namespace std;

CEins::CEins()
{
	cout << "CEins: 4" << endl;
	this->~CEins();
}


CEins::~CEins()
{
	cout << "~CEins: 5" << endl;
}
