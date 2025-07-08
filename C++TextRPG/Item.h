#pragma once

#include "MainSystem.h"
#include "Inventory.h"

using namespace std;

class cItem : public cMainSystem
{
public:
	cItem();
	virtual ~cItem();

	virtual void SelectItemCode(cMainSystem* Inventory, cMainSystem* MainSystem);

	virtual void UseBread(cMainSystem* MainSystem);
	virtual void UseHealingPotion(cMainSystem* MainSystem);
	
protected:

private:
	int m_nBreadCode;
	int m_nHealingPotionCode;

	int m_nMyBread;
	int m_nMyHealingPotion;
};