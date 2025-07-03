#pragma once

#include "MainSystem.h"

using namespace std;

class cSocerer : public cMainSystem
{
public:
	cSocerer();
	virtual ~cSocerer();

	virtual void CharacterUi();

	virtual void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster);

	virtual void Setm_nHealth(int nDamage);

protected:

private:

};