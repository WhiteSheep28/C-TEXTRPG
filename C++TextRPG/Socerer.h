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

protected:

private:

};