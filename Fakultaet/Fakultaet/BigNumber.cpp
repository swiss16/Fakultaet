#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>
#include <conio.h>

using namespace std;


CBigNumber::CBigNumber()
{
	m_basicNumber = new int(10);
	m_isPositive = new bool(true);
	m_validDigits = new int(1);
	
	m_digits[0] = new int(1);
	for (int i = 1; i < 5; i++)
	{
		m_digits[i] = new int(0);
	}
	
}

CBigNumber::CBigNumber(const CBigNumber& bigNumber)
	:m_basicNumber(new int(*bigNumber.m_basicNumber)),
	m_isPositive(new bool(*bigNumber.m_isPositive)),
	m_validDigits(new int(*bigNumber.m_validDigits))
{
	//memcpy(*bigNumber.m_digits, m_digits, 5);//Kopiert ein Array (Von, Nach, Arraygrösse)
	for (int i = 0; i < 5; i++)
	{
		delete m_digits[i];
		m_digits[i] = new int(*bigNumber.m_digits[i]);
	}
}

CBigNumber::~CBigNumber()
{
	delete m_basicNumber;
	delete m_isPositive;
	delete m_validDigits;
	for (int i = 0; i < 5; i++)
	{
		delete m_digits[i];
		m_digits[i] = NULL;
	}
	m_basicNumber=NULL;
	m_isPositive = NULL;
	m_validDigits = NULL;
}

CBigNumber& CBigNumber::operator=(CBigNumber& bigNumber)
{
	if (this != &bigNumber)
	{
	*m_basicNumber = *bigNumber.m_basicNumber;
	*m_isPositive = *bigNumber.m_isPositive;
	*m_validDigits = *bigNumber.m_validDigits;
	//memcpy(*bigNumber.m_digits, *m_digits, 5);//Kopiert ein Array (Von, Nach, Arraygrösse)
	for (int i = 0; i < 5; i++)
	{
		*m_digits[i] = *bigNumber.m_digits[i];
	}

	}
	return *this;
}
CBigNumber& CBigNumber::operator*(int number)
{
	//number von 19999 ergibt 77333 zeichen
	int _ValidDigits = *m_validDigits;
	int _result[5];
//Temporäres Array mit den digits werten füllen	
	for (int i = 0; i < 5; i++)
	{
		_result[i] = *m_digits[i];
	}
	//Jeden Int Multiplizieren
	for (int i = 0; i < _ValidDigits; i++)
	{
		_result[i] = *m_digits[i] * number;
	}
	return *this+_result;
}
CBigNumber& CBigNumber::operator+(int results[5])
{
	int _tempNumber = 0;
	int _tempUebertrag = 0;
	for (int i = 0; i < 5; i++)
	{
		_tempNumber = results[i];
		if (_tempNumber > *m_basicNumber-1)
		{
			_tempUebertrag = _tempNumber / *m_basicNumber;
			_tempNumber = _tempNumber % *m_basicNumber;
			results[i + 1] += _tempUebertrag;
		}
		
		*m_digits[i] = _tempNumber;
	}
	return *this;
}

CBigNumber& CBigNumber::fakultaet(int number)
{
	//Umwandlung von Negativen in Positiven Zahl
#pragma region Überprüfung
	if (number < 0){
		number = ((unsigned int)(-(1 + number))) + 1;
		*m_isPositive = false;
	}
	else{
		*m_isPositive = true; 
	}
#pragma endregion

		CBigNumber *_result = new CBigNumber;
		*_result = *this*number;


	return *_result;
}
