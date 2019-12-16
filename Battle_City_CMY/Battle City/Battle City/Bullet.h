#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"

/*The Bullet class inherits the Object class and needs to set the location, direction and color during initialization. 
The position of the shell needs to refer to the position of the tank launching the shell, 
and the moving direction is also related to the launching direction, so these parameters need to be obtained from the outside*/
class Bullet : public Object
{
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet();

	void Display();

	void Move();

	void Boom(list<Object*>& lstBombs);

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
};

#endif