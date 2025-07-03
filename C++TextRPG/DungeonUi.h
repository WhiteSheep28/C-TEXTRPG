#pragma once

#include "MainSystem.h"

using namespace std;

class cDungeonUi : public cMainSystem
{
public:
	cDungeonUi();
	virtual ~cDungeonUi();

	virtual void DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory);

	virtual void DungeonFightUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monsterc, cMainSystem* Inventory);

	void DungeonRandomItem();

	int Getm_nRandomItem() { return m_nRandomItem; }

protected:
	int m_nRandomMonster;
	int m_nRandomItem;

private:

};
