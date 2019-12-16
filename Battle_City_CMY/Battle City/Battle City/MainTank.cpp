#include "MainTank.h"

#include "Bullet.h"

/*Modify the value of the member variable. 
Through this function, the direction of the tank can be changed*/
void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

/*This function is responsible for drawing the theme part of the tank, a square tank body and two fillet rectangle tracks. 
And the shape of tank moving up and down and left and right is different. 
Here we judge the shape of the tank by its current direction*/
void MainTank::DrawTankBody()
{
	fillroundrect(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6, 3, 3);

	switch (m_dir)
	{
	case UP:
	case DOWN:
		fillroundrect(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY(), 3, 3);
		fillroundrect(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY(), 3, 3);
		break;
	case LEFT:
	case RIGHT:
		fillroundrect(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4, 3, 3);
		fillroundrect(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY(), 3, 3);
		break;
	default:
		break;
	}
}

/*This is the core drawing method, which is provided for external calls. Here are two parts of the work:
1.Determine the direction of the tank, then call DrawTankBody() to draw the tank body.
2.Draw the barrel according to the direction of moving*/
void MainTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	/*Setfillcolor() set fill color*/
	setfillcolor(m_color);
	/*SetColor() makes the painted tank border is the same as the color we set*/
	setcolor(m_color);

	DrawTankBody();

	switch (m_dir)
	{
	case UP:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);
		break;
	case DOWN:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);
		break;
	case LEFT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());
		break;
	case RIGHT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

/*Every time this function is executed, the tank moves forward by m_step length.
When the tank reaches the edge, it stops moving*/
void MainTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
			m_pos.SetY(m_pos.GetY() + m_step);
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
			m_pos.SetY(m_pos.GetY() - m_step);
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
			m_pos.SetX(m_pos.GetX() + m_step);
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
			m_pos.SetX(m_pos.GetX() - m_step);
		break;
	default:
		break;
	}

	/*Every time we move, we need to call the calculatesphere() method to recalculate the tank area*/
	CalculateSphere();
}

void MainTank::CalculateSphere()
{
	switch (m_dir)
	{
	case UP:
	case DOWN:
		m_rectSphere.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_rectSphere.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}

/*Each time this method is called, a new Bullet is created and added to the incoming list. 
When creating a bullet, we give the tank's own attributes to the bullet object*/
void MainTank::Shoot(list<Object*>& lstBullets)
{
	Bullet* pBullet = new Bullet(m_pos, m_dir, m_color);
	pBullet->SetStep(20);

	lstBullets.push_back(pBullet);
}

bool MainTank::CheckSup_Weapon()
{
	return Super_Weapon;
}

void MainTank::SetSup_Weapon()
{
	Super_Weapon = true;
}

void MainTank::Boom(list<Object*>& lstBombs)
{

}