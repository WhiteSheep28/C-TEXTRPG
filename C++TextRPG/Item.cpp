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
			cout << "������ ����" << endl;
		}
		case 1:
		{
			cout << "�� " << m_nMyBread << "��" << endl;
		}
		case 2:
		{
			cout << "ü������ " << m_nMyHealingPotion << "��" << endl;
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
