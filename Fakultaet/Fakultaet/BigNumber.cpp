#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>
#include <conio.h>

using namespace std;


CBigNumber::CBigNumber()
{
	m_basicNumber = new int(1000);
	m_isPositive = new bool(true);
	m_validDigits = new int(1);
	m_digits[0] = new int(1);
	for (int i = 1; i < 1001; i++)
	{
		m_digits[i] = new int(0);
	}
	
}

CBigNumber::CBigNumber(const CBigNumber& bigNumber)
	:m_basicNumber(new int(*bigNumber.m_basicNumber)),
	m_isPositive(new bool(*bigNumber.m_isPositive)),
	m_validDigits(new int(*bigNumber.m_validDigits))
{
	//memcpy(*bigNumber.m_digits, m_digits, 1001);//Kopiert ein Array (Von, Nach, Arraygrösse)
	for (int i = 0; i < 1001; i++)
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
	for (int i = 0; i < 100; i++)
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
	//memcpy(*bigNumber.m_digits, *m_digits, 1001);//Kopiert ein Array (Von, Nach, Arraygrösse)
	for (int i = 0; i < 1001; i++)
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
	//CBigNumber _result = *this;
	int _result[1001];
//Temporäres Array mit den digits werten füllen	
	for (int i = 0; i < 1001; i++)
	{
		_result[i] = *m_digits[i];
	}
	//Jeden Int Multiplizieren
	for (int i = 0; i < _ValidDigits; i++)
	{
		_result[i] = *m_digits[i] * number;
	}
	
	//return *this+=*_result.m_digits;
	return *this+=_result;
}
CBigNumber& CBigNumber::operator+=(int results[])
{
	int _tempNumber = 0;
	int _tempUebertrag = 0;
	for (int i = 0; i < 1001; i++)
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
	*m_validDigits = 1001;
	
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
	m_digits[0] = new int(1);
	for (int i = 1; i < 1001; i++)
	{
		m_digits[i] = new int(0);
	}
	
#pragma endregion
	if (number != 0)
	{
		for (int i = 1; i <= number; i++)
		{
			*this = *this*i;
		}
	
		
		
	}

	return *this;
}

ostream& operator<<(ostream& o, const CBigNumber& num)
{
	int count = 0;
	int _validDigits = 1001-1;
	bool finish = false;
	while (finish == false)
	{
		if (*num.m_digits[_validDigits] == 0)
		{
				_validDigits--;
		}
		else
		{
			finish = true;
		}
	}
	o << "Resultat: ";
	
	for (int i = _validDigits; i >= 0; i--)
	{
		if (i != 0)
		{
			if (*num.m_digits[i] < 100)
			{
				o << "0";
				if (*num.m_digits[i] < 10)
				{
					o << "0";
				}
				o << *num.m_digits[i] << "'";
				
				
			}
			else
			{
				o << *num.m_digits[i] << "'";
			}
			
		}
		else
		{
			if (*num.m_digits[0] == 0)
			{
				o << "000'000";
			}
			else
			{
				o << *num.m_digits[0];
			}
			
		}
		
		
	}
	return o;
}
