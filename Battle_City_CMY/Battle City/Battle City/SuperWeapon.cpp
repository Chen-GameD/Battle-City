#include "SuperWeapon.h"

#include "Bomb.h"

void SuperWeapon::RandomWeapon()
{
	m_pos.SetX(rand() % (Graphic::GetBattleGround().GetWidth() - 30) + 400);
	m_pos.SetY(rand() % (Graphic::GetBattleGround().GetHeight() - 30) + 400);
	m_color = RGB(248,133,133);
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step = 5;
	m_stepCnt = rand();
}

SuperWeapon::~SuperWeapon()
{

}

void SuperWeapon::RandomDir(int type)
{
	if (type == 1)
	{
		Dir dir;
		while ((dir = (Dir)(Dir::UP + (rand() % 4))) == m_dir)
		{
			// Do nothing
		}

		m_dir = dir;
	}
	else
	{
		m_dir = (Dir)(Dir::UP + (rand() % 4));
	}
}

// Mapping
void SuperWeapon::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	POINT pts[] = { {m_pos.GetX() - 17, m_pos.GetY() + 10}, {m_pos.GetX() + 17, m_pos.GetY() + 10}, {m_pos.GetX(), m_pos.GetY() - 20} };
	fillpolygon(pts, 3);

	//Here I drew three circles whose radius increases by one unit in order to make the edges of the circle look thicker.
	circle(m_pos.GetX(), m_pos.GetY(), 20);
	circle(m_pos.GetX(), m_pos.GetY(), 21);
	circle(m_pos.GetX(), m_pos.GetY(), 22);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

// Move
void SuperWeapon::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() + m_step);
			this->RandomDir(1);
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
		{
			m_pos.SetY(m_pos.GetY() - m_step);
			this->RandomDir(1);
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() + m_step);
			this->RandomDir(1);
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
		{
			m_pos.SetX(m_pos.GetX() - m_step);
			this->RandomDir(1);
		}
		break;
	default:
		break;
	}

	CalculateSphere();

	m_stepCnt++;
	if (m_stepCnt % MAX_STEP_TURN == 0)
	{
		//m_stepCnt = 0;
		this->RandomDir(0);
	}
}

void SuperWeapon::Boom(list<Object*>& lstBombs)
{
	lstBombs.push_back(new Bomb(m_pos, SMALL));
}

void SuperWeapon::CalculateSphere()
{
	m_rectSphere.Set(m_pos.GetX() - 15, m_pos.GetY() - 15, m_pos.GetX() + 15, m_pos.GetY() + 15);
}