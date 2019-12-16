#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include <list>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "Shape.h"
#include "Setting.h"
#include "SuperWeapon.h"

using namespace std;

MainTank mainTank;

// Bullet list
list<Object*> lstMainTankBullets;
list<Object*> lstBullets;

// Bomb List
list<Object*> lstBombs;

// Tank list
list<Tank*> lstTanks;

// SuperWeapon
SuperWeapon SP;

void CheckCrash()
{
	//Check if the SuperWeapon collides with the MainTank
	Rect a = SP.GetSphere();
	Rect b = mainTank.GetSphere();
	if (Shape::CheckIntersect(a, b))
	{
		Setting::SetWeapon();

		SP.SetDisappear();
	}

	// Check enermy tank damage
	/*Traverse the MainTank bullet list and tank list of the main battle tank respectively, and check the collision between them. 
	If there is any intersection, set the two elements to disappear through the interface*/
	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		for (list<Tank*>::iterator itt = lstTanks.begin(); itt != lstTanks.end(); itt++)
		{
			Rect a = (*it)->GetSphere();
			Rect b = (*itt)->GetSphere();
			if (Shape::CheckIntersect(a, b))
			{
				(*itt)->SetDisappear();
				(*it)->SetDisappear();
			}
		}
	}

	// Check main tank damage
	/*When the EnemyTank bullets contacts the main battle tank, the MainTank health value is reduced by one. 
	Our preset MainTank has five lives in total. 
	After being hit five times, the game ends.*/
	/*The newly added code detects the collision between the sphere of the MainTank and the sphere of the shell of each enemy tank through a for loop. 
	If it intersects, call the Setting:: Die() function to reduce the life of the MainTank by one. 
	When the health value is 0, use the SetDisappear() function to make the MainTank disappear.*/
	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		Rect a = (*it)->GetSphere();
		Rect b = mainTank.GetSphere();
		if (Shape::CheckIntersect(a, b))
		{
			Setting::Die();

			if (Setting::GetLife() > 0)
			{
				(*it)->SetDisappear();
			}
			else
			{
				mainTank.SetDisappear();
			}
		}
	}
}

void Init()
{
	srand((unsigned)time(NULL));

	Graphic::Create();

	lstMainTankBullets.clear();
	lstBullets.clear();
	lstBombs.clear();
	lstTanks.clear();
}

void Dispose()
{
	for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete* it;
	}
	lstTanks.clear();

	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		delete* it;
	}

	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		delete* it;
	}
	lstBullets.clear();

	for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end(); it++)
	{
		delete* it;
	}
	lstBombs.clear();

	Graphic::Destroy();
}

void main()
{
	Init();

	bool loop = true;
	bool skip = false;
	//The bGameOver variable is used to indicate the end of the game
	bool bGameOver = false;
	while (loop)
	{
		/*We capture the keyboard action through kbhit (), and then get the code value of the pressed key through getch(). 
		With the code value, we can do the corresponding operation*/
		if (kbhit())
		{
			int key = getch();
			if (skip && key != 13)
			{
				continue;
			}

			Dir dirBak;
			switch (key)
			{
				// Up
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
				// Down
			case 80:
				mainTank.SetDir(Dir::DOWN);
				break;
				// Left
			case 75:
				mainTank.SetDir(Dir::LEFT);
				break;
				// Right
			case 77:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: // Direction key height 8 bits
				break;
				// Esc
			case 27:
				loop = false;
				break;
				// Space
			case 32:
				/*After pressing the space bar, call maintank's shoot method to add a new bullet to the shell collection*/
				mainTank.Shoot(lstMainTankBullets);
				break;
				// Q
			case 113:
				//When we press the "Q" key, we fire shells in four directions at the same time
				if (Setting::GetSW())
				{
                    dirBak = mainTank.GetDir();
				    mainTank.SetDir(Dir::UP);
				    mainTank.Shoot(lstMainTankBullets);
				    mainTank.SetDir(Dir::DOWN);
				    mainTank.Shoot(lstMainTankBullets);
				    mainTank.SetDir(Dir::LEFT);
				    mainTank.Shoot(lstMainTankBullets);
				    mainTank.SetDir(Dir::RIGHT);
				    mainTank.Shoot(lstMainTankBullets);
				    mainTank.SetDir(dirBak);
				}
				break;
				// Enter  :suspend/start/exit
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}

		if (!skip)
		{
			if (bGameOver)
			{
				break;
			}

			// Draw Background
			cleardevice();
			Graphic::DrawBattleGround();

			CheckCrash();

			Graphic::ShowScore();

			// New Game Level
			if (Setting::m_bNewLevel)
			{
				Setting::m_bNewLevel = false;

				//Initializing related variables of a new level
				Setting::NewGameLevel();

				//Draw the prompt message just now
				Graphic::ShowGameLevel(Setting::GetGameLevel());

				//Create enemy tank in new level
				for (int i = 0; i < Setting::GetTankNum(); i++)
				{
					EnemyTank* p = new EnemyTank();
					lstTanks.push_back(p);
				}


				// Set pause, press enter to start
				skip = true;
				continue;
			}

			if (mainTank.IsDisappear())
			{
				skip = true;
				bGameOver = true;

				Graphic::ShowGameOver();

				continue;
			}

			mainTank.Move();
			mainTank.Display();

			
			if (!SP.IsDisappear() && Setting::GetSWE())
			{
				SP.Move();
			    SP.Display();
			}

			/* Draw Tanks */
			for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					Setting::TankDamaged();

					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the tank
					delete* it;
					it = lstTanks.erase(it);
					continue;
				}

				(*it)->Display();

				//When it is judged that the return value of NeedShoot() is true, the Shoot() function is called for shooting
				if ((*it)->NeedShoot())
				{
					EnemyTank* p = (EnemyTank*)*it;
					p->Shoot(lstBullets);
				}
				it++;
			}

			/* Draw Bullets */
			for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete* it;
					it = lstMainTankBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete* it;
					it = lstBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			/* Draw Bombs */
			for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					delete* it;
					it = lstBombs.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}
		}

		Sleep(30);
	}

	// Destroy
	Dispose();
}