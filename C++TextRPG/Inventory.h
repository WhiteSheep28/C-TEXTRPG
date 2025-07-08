#pragma once

#include "MainSystem.h"

using namespace std;

class cInventory : public cMainSystem
{
public:
	cInventory();
	virtual ~cInventory();

	virtual void InventoryUi(cMainSystem* pMainSystem, cMainSystem* Character,cMainSystem* Item, cMainSystem* Inventory);
	virtual void InputInventory(int ItemCode, int ItemNum);
	virtual void CleanInventory();

	void BreadUi();
	void HealthPotionUi();

protected:

private:

};