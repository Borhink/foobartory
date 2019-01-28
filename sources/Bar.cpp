#include "Bar.h"

int	Bar::m_iNextSerialNumber = 1;
const float	Bar::c_fMiningTimeMin = 0.5f;
const float	Bar::c_fMiningTimeMax = 2.0f;

Bar::Bar()
	: m_iSerialNumber(m_iNextSerialNumber)
{
	m_iNextSerialNumber++;
	printf("Bar created. Serial number : %#06x\n", m_iSerialNumber);
}

Bar::~Bar()
{
}

int Bar::GetSerialNumber() const
{
	return m_iSerialNumber;
}

float Bar::GetMiningTime()
{
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (c_fMiningTimeMax - c_fMiningTimeMin))) + c_fMiningTimeMin;
}