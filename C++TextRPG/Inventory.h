#pragma once

#include "MainSystem.h"

using namespace std;

class cInventory : public cMainSystem
{
public:

protected:
	//�κ��丮 Ui
	virtual void InventoryUi();
	//������ �Լ�
	virtual void GetItem();
	//�κ��丮 ����
	virtual void InventoryArrange();

private:
	//�κ��丮 ����
	int Inventory[11];
};