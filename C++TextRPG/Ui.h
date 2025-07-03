#pragma once

#include "MainSystem.h"

using namespace std;

class cUi : public cMainSystem
{
public:
	cUi();
	virtual ~cUi();

	virtual void StartMainUi();
	virtual void CharacterSelectUi(cMainSystem* pMainSystem);
	virtual void CharacterIntroduceUi(cMainSystem* pMainSystem, cMainSystem* Character);
	virtual void MainUi(cMainSystem* pMainSystem, cMainSystem* Character);

protected:

private:

};