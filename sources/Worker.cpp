#include "Worker.h"
#include "Bar.h"
#include "Foo.h"

const char* const Worker::m_cActivityName[5] = { "MiningBar", "MiningFoo", "Crafting", "Selling", "None" };

Worker::Worker()
	: m_eCurrentActivity(None)
	, m_eNextActivity(None)
	, m_fActivityTimer(0.0f)
	, m_fNextActivityTime (0.0f)
{
	printf("Worker created\n");
}

Worker::~Worker()
{
}

void Worker::Update(float elapsedTime)
{
	m_fActivityTimer -= elapsedTime;
}

bool Worker::IsActivityDone() const
{
	return m_fActivityTimer <= 0.0f;
}

Activity Worker::GetActivity() const
{
	return m_eCurrentActivity;
}

Activity Worker::GetNextActivity() const
{
	return m_eNextActivity;
}

void Worker::SetActivity(Activity eActivity)
{
	if (m_eCurrentActivity == eActivity)
	{
		StartNextActivity();
		return;
	}
	printf("Worker change activity : %s -> %s\n", Worker::m_cActivityName[m_eCurrentActivity], Worker::m_cActivityName[eActivity]);

	m_eCurrentActivity = None;
	m_fActivityTimer = 20.0f;
	m_eNextActivity = eActivity;

	switch (eActivity)
	{
	case MiningBar:
		m_fNextActivityTime = Bar::GetMiningTime();
		break;
	case MiningFoo:
		m_fNextActivityTime = Foo::GetMiningTime();
		break;
	case Crafting:
		m_fNextActivityTime = 2.0f;
		break;
	case Selling:
		m_fNextActivityTime = 10.0f;
		break;
	}
}

void Worker::StartNextActivity()
{
	if (IsActivityDone())
	{
		m_eCurrentActivity = m_eNextActivity;
		m_fActivityTimer = m_fNextActivityTime;
	}
}