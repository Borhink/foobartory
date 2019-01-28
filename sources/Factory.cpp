#include "Factory.h"
#include <algorithm>

Factory::Factory()
	: m_iMoney(0)
	, m_fTimerInfo(0.0f)
{
	m_cWorkers.push_back(Worker());
	m_cWorkers.push_back(Worker());
	memset(m_iWorks, 0, sizeof(m_iWorks));
}

Factory::~Factory()
{
	m_cWorkers.clear();
}

Activity Factory::ChangeActivity(Activity eActivity, Activity eNewActivity)
{
	m_iWorks[eActivity]--;
	m_iWorks[eNewActivity]++;
	return eNewActivity;
}

bool Factory::Update(float elapsedTime)
{
	for (unsigned int i = 0; i < m_cWorkers.size(); i++)
	{
		Worker& worker = m_cWorkers[i];
		int n;

		worker.Update(elapsedTime);
		if (worker.IsActivityDone())
		{
			switch (worker.GetActivity())
			{
			case MiningBar:
				m_cBars.push_back(Bar());
				break;
			case MiningFoo:
				m_cFoos.push_back(Foo());
				break;
			case Crafting:
				if (m_cFoos.size() < 1 || m_cBars.size() < 1)
				{
					printf("Worker cant craft foobar\n");
				}
				else
				{
					printf("Crafting foobar -> ");
					n = rand() % 100;
					if (n < Foobar::GetSuccessRate())
					{
						m_cFoobars.push_back(Foobar(m_cFoos.back(), m_cBars.back()));
						m_cBars.pop_back();
					}
					else
						printf("failed\n");
					m_cFoos.pop_back();
				}
				break;
			case Selling:
				n = 1 + rand() % 5;
				if (n > m_cFoobars.size())
					n = m_cFoobars.size();
				if (n > 0)
					printf("Worker has sold %d foobar\n", n);
				else
					printf("No foobar, worker cant sell\n");
				m_iMoney += n;
				m_cFoobars.resize(m_cFoobars.size() - n);
				break;
			case None:
				worker.StartNextActivity();
				break;
			default:
				break;
			}


			Activity eActivity = worker.GetActivity();
			Activity eCurrentActivity = worker.GetActivity();
			if (eActivity == None && worker.GetNextActivity() != None)
				continue;

			int iMaxFooMiner = m_cWorkers.size() / 2 + m_cWorkers.size() % 2 - ((m_cFoos.size() + 1) / (m_cBars.size() + 2));
			int iMaxBarMiner = m_cWorkers.size() / 2 - ((m_cBars.size() + 1) / (m_cFoos.size() + 2));
			int iDiffFooBar = m_cFoos.size() - m_cBars.size();
			if (m_iWorks[MiningFoo] < iMaxFooMiner || (eCurrentActivity == MiningFoo && iDiffFooBar < 20))
				eActivity = ChangeActivity(eActivity, MiningFoo);
			else if (m_iWorks[MiningBar] < iMaxBarMiner || (eCurrentActivity == MiningBar && -iDiffFooBar < 20))
				eActivity = ChangeActivity(eActivity, MiningBar);

			if (m_iWorks[Selling] < 1 + m_cFoobars.size() / 12 && m_cFoobars.size() > 6 || (worker.GetActivity() == Selling && m_cFoobars.size() > 2))
				eActivity = ChangeActivity(eActivity, Selling);
			else if ((m_iWorks[Crafting] < std::min(m_cFoos.size(), m_cBars.size()) / 10 && m_cFoos.size() > 21 && m_cBars.size() > 15 && m_iMoney < 3)
				|| (worker.GetActivity() == Crafting && m_cFoos.size() > 6 && m_cBars.size() > 6))
				eActivity = ChangeActivity(eActivity, Crafting);

			if (eActivity != None)
				worker.SetActivity(eActivity);
		}
	}

	while (BuyWorker());

	m_fTimerInfo -= elapsedTime;
	if (m_fTimerInfo <= 0.0f || m_cWorkers.size() >= 100)
	{
		printf("Worker number : %d\n", m_cWorkers.size());
		printf("Foo number : %d\n", m_cFoos.size());
		printf("Bar number : %d\n", m_cBars.size());
		printf("Foobar number : %d\n", m_cFoobars.size());
		printf("Money : %d\n", m_iMoney);
		m_fTimerInfo = 5.0f;
	}

	return m_cWorkers.size() >= 100;
}

bool Factory::BuyWorker()
{
	if (m_iMoney >= 3 && m_cFoos.size() >= 6)
	{
		m_iMoney -= 3;
		m_cFoos.resize(m_cFoos.size() - 6);
		m_cWorkers.push_back(Worker());
		return true;
	}
	return false;
}