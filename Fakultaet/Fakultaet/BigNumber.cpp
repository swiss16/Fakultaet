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
	memcpy(*bigNumber.m_digits, m_digits, 5);//Kopiert ein Array (Von, Nach, Arraygr�sse)
}

CBigNumber::~CBigNumber()
{
	delete m_basicNumber;
	delete *m_digits;
	delete m_isPositive;
	delete m_validDigits;
	m_basicNumber=NULL;
	*m_digits = NULL;
	m_isPositive = NULL;
	m_validDigits = NULL;
}

CBigNumber& CBigNumber::operator=(CBigNumber& bigNumber)
{
	return *this;
}
CBigNumber& CBigNumber::operator*(int number)
{
	//number von 19999 ergibt 77333 zeichen
	int _ValidDigits = *m_validDigits;
	int _result[5];
//Tempor�res Array mit den digits werten f�llen	
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
		for (int i = *m_basicNumber; i < _tempNumber; i**m_basicNumber)
		{
			//TODO: Logik umdenken, Wie k�nnte ich die einzzelnen Zahlen gem�ss Basis auslesen
		}
	}
	return *this;
}

CBigNumber& CBigNumber::fakultaet(int number)
{
	//Umwandlung von Negativen in Positiven Zahl
#pragma region �berpr�fung
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


	return *this;
}
