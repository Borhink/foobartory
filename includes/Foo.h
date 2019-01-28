#ifndef FOO_H
#define FOO_H

#include <string>

class Foo
{

public:

	Foo();
	~Foo();

	int GetSerialNumber() const;
	static float GetMiningTime();

private:
	static int			m_iNextSerialNumber;
	static const float	c_fMiningTime;

	int		m_iSerialNumber;
};

#endif