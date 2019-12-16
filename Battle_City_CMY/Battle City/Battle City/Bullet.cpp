#include "Bullet.h"

#include "Bomb.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Point pos, Dir dir, COLORREF color)
{
	m_pos = pos;
	m_dir = dir;
	m_color = color;

	/*m_step is set to 6, because the speed of the bullet must be faster than main tank, so that to make sense*/
	m_step = 6;

	m_bDisappear = false;

	CalculateSphere();
}

Bullet::~Bullet()
{

}


// Mapping
/*In Display(), we fill a round bullet with its position and color*/
void Bullet::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillcircle(m_pos.GetX(), m_pos.GetY(), 3);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

// Move
void Bullet::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		CalculateSphere();
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(Graphic::GetBattleGround().GetStartPoint().GetY());
			m_bDisappear = true;
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		CalculateSphere();
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
		{
			m_pos.SetY(Graphic::GetBattleGround().GetEndPoint().GetY());
			m_bDisappear = true;
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		CalculateSphere();
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
		{
			m_pos.SetX(Graphic::GetBattleGround().GetStartPoint().GetX());
			m_bDisappear = true;
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		CalculateSphere();
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
		{
			m_pos.SetX(Graphic::GetBattleGround().GetEndPoint().GetX());
			m_bDisappear = true;
		}
		break;
	default:
		break;
	}
}

/*It's almost the same as the MainTank shoot() method. 
Here, a Bomb object is created to join the explosion list of lstbots. 
The position of the explosion is the current position of the shell*/
void Bullet::Boom(list<Object*>& lstBombs)
{
	lstBombs.push_back(new Bomb(m_pos, SMALL));
}

void Bullet::CalculateSphere()
{
	m_rectSphere.Set(m_pos.GetX() - 2, m_pos.GetY() - 2, m_pos.GetX() + 2, m_pos.GetY() + 2);
}