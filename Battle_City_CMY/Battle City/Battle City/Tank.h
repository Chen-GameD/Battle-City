#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"
#include "Bomb.h"

#include <list>

using namespace std;

/*Our program is to be drawn on the screen through EasyX. 
All kinds of elements need to be placed in a data structure that can be traversed for convenient operation, 
so we will use polymorphism when implementing tank code*/
class Tank : public Object
{
public:
	Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 2;

		m_bDisappear = false;
		m_bNeedShoot = false;
	}

	~Tank() {}

	void Display()
	{
		// Display
	}

	void Move()
	{
		// Move
	}

	//When a tank explodes, create a LARGE explosion
	void Boom(list<Object*>& lstBombs)
	{
		lstBombs.push_back(new Bomb(m_pos, LARGE));
	}

	// Shoot
	/*The parameter of this function is an object pointer list. 
	The firing method we need to implement is to add new bullet information to the incoming list*/
	void Shoot(list<Object*>& lstBullets)
	{
		// Shoot
	}

	void SetDisappear()
	{
		m_bDisappear = true;
	}

	bool IsDisappear()
	{
		return m_bDisappear;
	}

	Rect GetSphere()
	{
		return m_rectSphere;
	}

	bool NeedShoot()
	{
		return m_bNeedShoot;
	}

protected:
	void CalculateSphere()
	{
		// Calculate Sphere
	}

	//It is used for automatic firing of enemy tank, and judge whether to execute the Shoot() function through its attributes
	bool m_bNeedShoot;
	bool Super_Weapon;
};

#endif