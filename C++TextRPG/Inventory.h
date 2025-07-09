#pragma once

#include "MainSystem.h"
#include "Character.h"

using namespace std;

class cInventory : public cMainSystem
{
public:
	cInventory();
	virtual ~cInventory();

	//�κ��丮 Ui
	virtual void InventoryUi(cMainSystem* MainSystem, cMainSystem* Character,cMainSystem* Item);
	//������ �Լ�
	virtual void GetItem(cMainSystem* Character,cMainSystem* Item, int ItemNum, int ItemCount);
	//�κ��丮 ����
	virtual void InventoryArrange();

protected:

private:
	//�κ��丮 ����
	int Inventory[11];

	int m_nCount;

	friend class cCharacter;
};