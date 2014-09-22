#pragma once
class CBigNumber
{
private:
	int *m_digits[5];
	bool *m_isPositive;
	int *m_validDigits;
	int *m_basicNumber;

public:
	CBigNumber();
	CBigNumber(const CBigNumber& bigNumber);
	~CBigNumber();

	CBigNumber& operator=(CBigNumber& bigNumber);
	CBigNumber& operator*(int number);
	CBigNumber& operator+=(int results[5]);

	CBigNumber& fakultaet(int number);

	
};

