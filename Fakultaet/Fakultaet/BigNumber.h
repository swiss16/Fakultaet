#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
class CBigNumber
{
private:
	bool *m_isPositive;
	int *m_validDigits;
	int *m_basicNumber;
	int *m_digits[1001];

public:
	CBigNumber();
	CBigNumber(const CBigNumber& bigNumber);
	~CBigNumber();

	CBigNumber& operator=(CBigNumber& bigNumber);
	CBigNumber& operator*(int number);
	CBigNumber& operator+=(int results[1000]);

	CBigNumber& fakultaet(int number);

	friend ostream& operator<<(ostream& o, const CBigNumber&);

	
};
ostream& operator<<(ostream& o, const CBigNumber& number);

