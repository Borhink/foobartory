#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <vector>
#include "Worker.h"
#include "Bar.h"
#include "Foo.h"
#include "Foobar.h"

class Factory
{

public:

	Factory();
	~Factory();

	Activity ChangeActivity(Activity eActivity, Activity eNewActivity);
	bool Update(float elapsedTime);
	bool BuyWorker();

private:
	std::vector<Worker> m_cWorkers;
	std::vector<Foo> m_cFoos;
	std::vector<Bar> m_cBars;
	std::vector<Foobar> m_cFoobars;

	int		m_iMoney;
	float	m_fTimerInfo;

	int		m_iWorks[5];
};

#endif

//Buy worker 3€ + 6 foo