#include <iostream>

#include "MainSystem.h"
#include "Item.h"
#include "Inventory.h"
#include "Character.h"

cItem::cItem()
{

}

cItem::~cItem()
{

}

void cItem::SearchItemCode(cMainSystem* Character, int ItemNum, int SelectTool)
{
	if (SelectTool == 1)
	{
		switch (ItemNum)
		{
		case 0:
		{
			cout << "아이템 없음" << endl;
		}
		case 1:
		{
			cout << "빵 " << m_nMyBread << "개" << endl;
		}
		case 2:
		{
			cout << "체력포션 " << m_nMyHealingPotion << "개" << endl;
		}
		}
	}
	else if (SelectTool == 2)
	{
		switch (ItemNum)
		{
		case 0:
		{

		}
		case 1:
		{
			Character->UseBread();
		}
		case 2:
		{
			Character->UseHealingPotion();
		}
		}
	}
}
