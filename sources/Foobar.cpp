#include "Foobar.h"

int			Foobar::m_iNextSerialNumber = 1;
const int	Foobar::c_iSuccessRate = 60;

Foobar::Foobar()
{
}

Foobar::Foobar(Foo oFoo, Bar oBar)
	: m_iSerialNumber(m_iNextSerialNumber)
	, m_oFoo(oFoo)
	, m_oBar(oBar)
{
	m_iNextSerialNumber++;
	printf("Foobar created. Serial number : %#06x (F%#06x, B%#06x)\n", m_iSerialNumber, GetFooSerialNumber(), GetBarSerialNumber());
}

Foobar::~Foobar()
{
}

int Foobar::GetSerialNumber() const
{
	return m_iSerialNumber;
}

int Foobar::GetFooSerialNumber() const
{
	return m_oFoo.GetSerialNumber();
}

int Foobar::GetBarSerialNumber() const
{
	return m_oBar.GetSerialNumber();
}

int Foobar::GetSuccessRate()
{
	return c_iSuccessRate;
}