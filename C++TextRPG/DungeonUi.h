#pragma once

#include "MainSystem.h"

using namespace std;

class cDungeonUi : public cMainSystem
{
public:
	cDungeonUi();
	virtual ~cDungeonUi();

	virtual void DungeonRandomMob(cMainSystem* pMainSystem, cMainSystem* Character);

	virtual void DungeonFightUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster);

protected:
	int m_nRandomMonster;

private:

};
