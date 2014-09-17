#include "stdafx.h"
#include "BigNumber.h"
#include <iostream>
#include <conio.h>

using namespace std;


CBigNumber::CBigNumber()
{

}

CBigNumber::CBigNumber(const CBigNumber& bigNumber)
	:m_basicNumber(new int(*bigNumber.m_basicNumber)),
	m_isPositive(new bool(*bigNumber.m_isPositive)),
	m_validDigits(new int(*bigNumber.m_validDigits))
{
	memcpy(*bigNumber.m_digits, m_digits, 5);
}

CBigNumber::~CBigNumber()
{

}

CBigNumber& CBigNumber::operator=(CBigNumber& bigNumber)
{

}
CBigNumber& CBigNumber::operator*(CBigNumber& bigNumber)
{

}
CBigNumber& CBigNumber::operator+(CBigNumber& bigNumber)
{

}

CBigNumber& CBigNumber::fakultaet(int number)
{

}
