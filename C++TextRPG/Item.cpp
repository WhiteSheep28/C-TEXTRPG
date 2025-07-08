#include <iostream>

#include "MainSystem.h"
#include "Item.h"

using namespace std;

cItem::cItem()
{

}

cItem::~cItem()
{

}

 void cItem::SelectItemCode(cMainSystem* Inventory, cMainSystem* MainSystem)
{
	switch (Inventory->Getm_nInventorySlot())
	{
	case 1:
	{
		UseBread(MainSystem);
		break;
	}
	case 2:
	{
		UseHealingPotion(MainSystem);
		break;
	}
	}
}

void cItem::UseBread(cMainSystem* MainSystem)
{
	m_nMyBread--;

	MainSystem->Setm_nPlusHungry();
}

void cItem::UseHealingPotion(cMainSystem* MainSystem)
{
	m_nMyHealingPotion--;

	MainSystem->Setm_nPlusHealth();
}