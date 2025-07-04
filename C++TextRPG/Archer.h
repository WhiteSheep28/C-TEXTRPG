#pragma once

#include "MainSystem.h"

using namespace std;

class cArcher : public cMainSystem
{
public:
	cArcher();
	virtual ~cArcher();

	virtual void SkillTree(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Monster);

protected:

private:

};