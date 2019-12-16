#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank() : Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = RGB(46, 236, 237);
		m_dir = Dir::UP;
		m_step = 4;
		Super_Weapon = false;
	}

	~MainTank() {}

	//Setting the direction of moving
	void SetDir(Dir dir);
	Dir GetDir()
	{
		return m_dir;
	}
	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullets);
	bool CheckSup_Weapon();
	void SetSup_Weapon();
	void Boom(list<Object*>& lstBombs);

protected:
	void CalculateSphere();

	// Draw tank body
	void DrawTankBody();
};

#endif