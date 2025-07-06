#pragma once

#include "MainSystem.h"

using namespace std;

class cFarmUi : public cMainSystem
{
public:
	cFarmUi();
	virtual ~cFarmUi();

	virtual void FarmUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory);

protected:

private:

};