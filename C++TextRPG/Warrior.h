#pragma once

#include "MainSystem.h"

using namespace std;

class cWarrior : public cMainSystem
{
public:
	cWarrior();
	virtual ~cWarrior();

	virtual void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster);

protected:

private:

};