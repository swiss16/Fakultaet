// Fakultaet.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	CBigNumber *bigNumber1 = new CBigNumber;
	int zahl;
	cout << "Zahl eingeben: ";
	cin >> zahl;
	bigNumber1->fakultaet(zahl);
	
	

	return 0;
}

