#ifndef __SETTING_H__
#define __SETTING_H__

#include <list>

using namespace std;

class Setting
{
public:
	//The NewGameLevel() function initializes the attribute information of each level at the beginning of each level
	static void NewGameLevel();
	//The TankDamaged() function, is called every time a tank is destroyed to complete the data, update of related attributes
	static void TankDamaged();

	static void SetWeapon();

	static int GetLife()
	{
		return m_nLife;
	}

	static void Die()
	{
		m_nLife -= 1;
	}

	static int GetGameLevel()
	{
		return m_nGameLevel;
	}

	static int GetTankLevel()
	{
		return m_nTankLevel;
	}

	static int GetTankNum()
	{
		return m_nTankNum;
	}

	static int GetSumScore()
	{
		return m_nSumScore;
	}

	static int GetTankSum()
	{
		return m_nTankSum;
	}

	static bool GetSWE() 
	{
		return SuperWeapon_E;
	}

	static bool GetSW()
	{
		return SuperWeapon;
	}

	static bool m_bNewLevel;

private:
	static int m_nLife; // HP

	static int m_nGameLevel;	// Current game stage
	static int m_nTankLevel;	// Current tank level

	static int m_nTankNum;		// Current number of tanks

	static int m_nSumScore;		// Total score

	static int m_nTankScore;	// Kill tank score

	static int m_nTankSum;		// Total number of tanks destroyed

	static bool SuperWeapon;    //

	static bool SuperWeapon_E;
};

#endif