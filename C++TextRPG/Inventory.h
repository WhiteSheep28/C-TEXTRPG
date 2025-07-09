#pragma once

#include "MainSystem.h"
#include "Character.h"

using namespace std;

class cInventory : public cMainSystem
{
public:
	cInventory();
	virtual ~cInventory();

	//인벤토리 Ui
	virtual void InventoryUi(cMainSystem* MainSystem, cMainSystem* Character,cMainSystem* Item);
	//아이템 입수
	virtual void GetItem(cMainSystem* Character,cMainSystem* Item, int ItemNum, int ItemCount);
	//인벤토리 정리
	virtual void InventoryArrange();

protected:

private:
	//인벤토리 공간
	int Inventory[11];

	int m_nCount;

	friend class cCharacter;
};