#pragma once

#include "MainSystem.h"

using namespace std;

class cDungeonUi : public cMainSystem
{
public:
	cDungeonUi();
	virtual ~cDungeonUi();

	virtual void DungeonStart(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory, cMainSystem* Item);
	virtual void DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory, cMainSystem* Item);
	virtual void DungeonFightUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monsterc, cMainSystem* Inventory, cMainSystem* Item);
	void DungeonRandomItem();

	int Getm_nRandomItem() { return m_nRandomItem; }

protected:
	int m_nRandomMonster;
	int m_nRandomItem;

private:

};
