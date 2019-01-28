#ifndef FOOBAR_H
#define FOOBAR_H

#include <string>
#include "Bar.h"
#include "Foo.h"

class Foobar
{

public:

	Foobar();
	Foobar(Foo oFoo, Bar oBar);
	~Foobar();

	int GetSerialNumber() const;
	int GetFooSerialNumber() const;
	int GetBarSerialNumber() const;
	static int GetSuccessRate();

	static const int	c_iSuccessRate;
private:
	static int			m_iNextSerialNumber;

	int		m_iSerialNumber;
	Foo		m_oFoo;
	Bar		m_oBar;


};

#endif