#ifndef __SUPERWEAPON_H__
#define __SUPERWEAPON_H__

#include "Object.h"

#define MAX_STEP_TURN	40

/*The content of the SuperWeapon is basically the same as that of the EnemyTank, 
but the collision detection object is different, 
so it should be allowed to detect the collision with the MainTank*/
class SuperWeapon : public Object
{
public:
	SuperWeapon()
	{
		RandomWeapon();
	}
	~SuperWeapon();

	void Display();

	void Move();

	void Boom(list<Object*>& lstBombs);

	void RandomWeapon();

	bool IsDisappear()
	{
		return m_bDisappear;
	}

	Rect GetSphere()
	{
		return m_rectSphere;
	}

	void SetStep(int nStep)
	{
		m_step = nStep;
	}

	void SetDisappear()
	{
		m_bDisappear = true;
	}

protected:
	void CalculateSphere();

	void RandomDir(int type);

	int m_stepCnt;
};

#endif