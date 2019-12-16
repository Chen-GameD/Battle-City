#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#include "Tank.h"

#define MAX_STEP_TURN	20
#define MAX_STEP_SHOOT	15

class EnemyTank : public Tank
{
public:
	EnemyTank()
	{
		RandomTank();
	}

	~EnemyTank() {}

	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullets);

protected:
	void CalculateSphere();
	/*RandomTank() is used to randomly generate a tank in the battlefield area*/
	void RandomTank();
	/*Randomly generate tank direction:(Variable of type) 
	1:The new direction must be different from the previous direction 
	0:Any new direction*/
	void RandomDir(int type);

	/*The m_stepCnt attribute is used to record the current steps of the tank*/
	int m_stepCnt;
};

#endif