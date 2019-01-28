#ifndef WORKER_H
#define WORKER_H

#include <string>

enum Activity { MiningBar, MiningFoo, Crafting, Selling, None };

class Worker
{

public:

	Worker();
	~Worker();

	void		Update(float elapsedTime);
	bool		IsActivityDone() const;
	Activity	GetActivity() const;
	Activity	GetNextActivity() const;
	void		SetActivity(Activity eActivity);
	void		StartNextActivity();

private:
	Activity	m_eCurrentActivity;
	Activity	m_eNextActivity;
	float		m_fActivityTimer;
	float		m_fNextActivityTime;

	static const char* const m_cActivityName[5];
};

#endif

//Mining
//Change activity 20sec
//Craft Foobar 2s
//Sell 10sec  (1 to 5)   1€