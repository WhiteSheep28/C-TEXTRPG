#pragma once

#include "MainSystem.h"

using namespace std;

class cInventory : public cMainSystem
{
public:
	cInventory();
	virtual ~cInventory();

	virtual void InventoryUi(cMainSystem* pMainSystem, cMainSystem* Character);
	void BreadUi();
	void HealthPotionUi();

protected:
	int m_nInventorySlot[8];

	int m_nBreadCode;
	int m_nHealingPotionCode;

	int m_nMyBread;
	int m_nMyHealingPotion;

private:

};