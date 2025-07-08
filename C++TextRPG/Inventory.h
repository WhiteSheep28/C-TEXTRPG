#pragma once

#include "MainSystem.h"

using namespace std;

class cInventory : public cMainSystem
{
public:

protected:
	//인벤토리 Ui
	virtual void InventoryUi();
	//아이템 입수
	virtual void GetItem();
	//인벤토리 정리
	virtual void InventoryArrange();

private:
	//인벤토리 공간
	int Inventory[11];
};