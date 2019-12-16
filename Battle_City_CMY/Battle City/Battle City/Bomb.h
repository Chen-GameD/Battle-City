#ifndef __BOMB_H__
#define __BOMB_H__

#include "Object.h"

//At present, we have defined two kinds: LARGE and SMALL, which are used to represent tank explosion and shell explosion respectively.
enum BombType
{
	LARGE,
	SMALL
};

/*The explosion is also managed as an independent element, and a new class, Bomb, is inherited from the object to implement*/

/*Since the object class is inherited, all virtual functions must be inherited. 
Two new attributes have been added. m_type is the type of bombtype, indicating the type of explosion.  
m_timer is used to control the state of explosion display. Our explosion should be an animation, not a static shape*/
class Bomb : public Object
{
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb() {}

	void Display();

	void Move();

	void Boom(list<Object*>& lstBombs);

	bool IsDisappear();
	void SetDisappear() {}

	Rect GetSphere()
	{
		return m_rectSphere;
	}

protected:
	void CalculateSphere();

	BombType m_type;
	int m_timer;
};

#endif