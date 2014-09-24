// Fakultaet.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	CBigNumber bigNumber1;
	//CBigNumber bigNumber2 = bigNumber1;
	//bigNumber2.~CBigNumber();
	//_CrtDumpMemoryLeaks();
	int zahl;
	cout << "Fakultät von: ";
	cin >> zahl;
	//stoppuhr
	unsigned int start = clock();
	bigNumber1.fakultaet(zahl);
	cout << bigNumber1;
	cout << endl;
	cout << "Die Berechnung hat " << clock() - start << " Milli-Sekunden gedauert." << endl;
	char egal;
	cin >> egal;
	return 0;
}

