#ifndef BAR_H
#define BAR_H

#include <string>

class Bar
{

public:

	Bar();
	~Bar();

	int GetSerialNumber() const;
	static float GetMiningTime();

private:
	static int			m_iNextSerialNumber;
	static const float	c_fMiningTimeMin;
	static const float	c_fMiningTimeMax;

	int		m_iSerialNumber;
};

#endif