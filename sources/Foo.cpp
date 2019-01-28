#include "Foo.h"

int			Foo::m_iNextSerialNumber = 1;
const float	Foo::c_fMiningTime = 1.0f;

Foo::Foo()
	: m_iSerialNumber(m_iNextSerialNumber)
{
	m_iNextSerialNumber++;
	printf("Foo created. Serial number : %#06x\n", m_iSerialNumber);
}

Foo::~Foo()
{
}

int Foo::GetSerialNumber() const
{
	return m_iSerialNumber;
}

float Foo::GetMiningTime()
{
	return c_fMiningTime;
}