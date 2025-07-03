#pragma once

#include "MainSystem.h"

using namespace std;

class cArcher : public cMainSystem
{
public:
	cArcher();
	virtual ~cArcher();

	virtual void CharacterUi();

	virtual void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster);

	virtual void Setm_nHealth(int nDamage);

protected:

private:

};