#include "Graphic.h"

#include "Setting.h"

Rect Graphic::m_rectScreen;
Rect Graphic::m_rectBattleGround;
char Graphic::m_pArray[100];

void Graphic::Create()
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(BLACK);

	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void Graphic::Destroy()
{
	closegraph();
}

/*The DrawBattleGround() function draws the scope of the battlefield on the screen*/
void Graphic::DrawBattleGround()
{
	rectangle(m_rectBattleGround.GetStartPoint().GetX(), m_rectBattleGround.GetStartPoint().GetY(),
		m_rectBattleGround.GetEndPoint().GetX(), m_rectBattleGround.GetEndPoint().GetY());
}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

Rect Graphic::GetBattleGround()
{
	return m_rectBattleGround;
}

const int SCORE_LEFT = 810;
const int SCORE_TOP = 5;

void Graphic::ShowScore()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	wsprintf((LPSTR)m_pArray, _T("Stage %d"), Setting::GetGameLevel());
	drawtext((LPCTSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("Score  :  %d"), Setting::GetSumScore());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("Level  :  %d"), Setting::GetTankLevel());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("H P  :  %d"), Setting::GetLife());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("Enemy  :  %d"), Setting::GetTankNum());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	if (Setting::GetSW())
	{
		wsprintf((LPSTR)m_pArray, _T("SuperWeapon  :  ON"));
		drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);
	}
	else
	{
        wsprintf((LPSTR)m_pArray, _T("SuperWeapon  :  OFF"));
	    drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);
	}
	
	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("Enemies Destroyed  :  %d"), Setting::GetTankSum());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


	setcolor(color_save);
	setfillcolor(fill_color_save);
}

/*This part of the code is similar to Cascading Style Sheets(CSS).
Use the library to output text and adjust the effect I want*/
void Graphic::ShowGameLevel(int nLevel)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 80, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 720, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // Get current font settings

	LOGFONT f = fontBak;
	f.lfHeight = 70;                      // Set font height to 70
	_tcscpy_s(f.lfFaceName, _T("icon-brand"));  // Set font to "icon-brand"
	f.lfQuality = ANTIALIASED_QUALITY;    // Set the output effect to antialiasing  
	settextstyle(&f);                     // Set font style
	wsprintf((LPSTR)m_pArray, _T("Stage %d"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 320, BATTLE_GROUND_Y1 + 250, (LPCTSTR)m_pArray);

	f.lfHeight = 25;
	settextstyle(&f);
	wsprintf((LPSTR)m_pArray, _T("Press Enter to start"));
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPCTSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Graphic::ShowGameOver()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 80, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 720, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // Get current font settings

	LOGFONT f = fontBak;
	f.lfHeight = 70;                      // Set font height to 70
	_tcscpy_s(f.lfFaceName, _T("icon-brand"));  // Set font to "icon-brand"
	f.lfQuality = ANTIALIASED_QUALITY;    // Set the output effect to antialiasing  
	settextstyle(&f);                     // Set font style
	wsprintf((LPSTR)m_pArray, _T("GAME OVER"));
	outtextxy(BATTLE_GROUND_X1 + 250, BATTLE_GROUND_Y1 + 250, (LPCTSTR)m_pArray);

	f.lfHeight = 25;
	settextstyle(&f);
	wsprintf((LPSTR)m_pArray, _T("Press Enter to exit"));
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPCTSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}