#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <graphics.h>

#include "Rect.h"

#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	768

/*We need to define an area for the game interface, and the other part will be used as the storage place for scoreboard and other information*/
#define BATTLE_GROUND_X1 5
#define BATTLE_GROUND_Y1 5
#define BATTLE_GROUND_X2 800
#define BATTLE_GROUND_Y2 (SCREEN_HEIGHT - BATTLE_GROUND_Y1)

/*Encapsulate EasyX canvas related functions in a graphic class*/
/*This class can realize the function of creating and destroying canvas, and can let other code get the size of canvas at any time through this class*/
class Graphic
{
public:
	static void Create();
	static void Destroy();

	static void DrawBattleGround();

	static int GetScreenWidth();
	static int GetScreenHeight();

	static Rect GetBattleGround();

	static void ShowScore();
	/*In the battle area, a rectangle is displayed with the Stage number printed in the middle*/
	static void ShowGameLevel(int nLevel);

	static void ShowGameOver();

private:
	static Rect m_rectScreen;
	/*The location of the battlefield area is defined by a set of macros in the file. 
	In addition, it is saved by the rect object m_rectBattleground*/
	static Rect m_rectBattleGround;

	static char m_pArray[100];
};

#endif