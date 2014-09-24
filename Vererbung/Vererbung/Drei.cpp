#include "stdafx.h"
#include "Drei.h"
#include <iostream>
#include <conio.h>
#include "Vier.h"

using namespace std;

CDrei::CDrei()
{
	cout << "CDrei: 3" << endl;
}


CDrei::~CDrei()
{
	//cout << "~CDrei: 7" << endl;
	cout << "~CDrei: 5" << endl;
}
