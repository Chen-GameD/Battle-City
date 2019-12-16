#include "Setting.h"

bool Setting::m_bNewLevel = true;

int Setting::m_nLife = 5;

int Setting::m_nGameLevel = 0;
int Setting::m_nTankLevel = 1;

int Setting::m_nTankNum = 5;

int Setting::m_nSumScore = 0;

int Setting::m_nTankScore = 5;

int Setting::m_nTankSum = 0;

bool Setting::SuperWeapon = false;

bool Setting::SuperWeapon_E = false;

void Setting::SetWeapon()
{
	SuperWeapon = true;
}

void Setting::NewGameLevel()
{
	m_nGameLevel++;

	//Check whether the Game Level is enough for SuperWeapon appear.
	if (m_nGameLevel == 3)
	{
		SuperWeapon_E = true;
	}

	m_nTankNum = 10 + 5 * (m_nGameLevel - 1);
	m_nTankScore += 5;
}

void Setting::TankDamaged()
{
	m_nTankNum--;
	m_nSumScore += m_nTankScore;

	m_nTankLevel = m_nSumScore / 150 + 1;

	//Every 500 points you get, you get another life
	if (m_nSumScore % 500 < m_nTankScore)
	{
		m_nLife++;
	}

	m_nTankSum++;

	if (m_nTankNum == 0)
	{
		m_bNewLevel = true;
	}
}