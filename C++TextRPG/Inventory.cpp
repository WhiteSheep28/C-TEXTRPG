#include <iostream>

#include "MainSystem.h"
#include "Inventory.h"
#include "Item.h"
#include "Character.h"

cInventory::cInventory()
{

}

cInventory::cInventory()
{

}

void cInventory::InventoryUi(cMainSystem* MainSystem, cMainSystem* Character, cMainSystem* Item)
{
	m_nCount = 0;

	while (m_nCount < 11)
	{
		cout << m_nCount << ". ";
		Item->SearchItemCode(MainSystem, Inventory[m_nCount], 1);
		m_nCount++;
	}

	MainSystem->Setm_nSelect();

	Item->SearchItemCode(Character ,Inventory[Getm_nSelect()], 2);

	InventoryArrange();
}

void cInventory::GetItem(cMainSystem* Character, cMainSystem* Item, int ItemNum, int ItemCount)
{
	m_nCount = 0;

	//�κ��丮�� �������� �ִ� ��� �ݺ����� ������ �������� ã�� �� ���Ѵ�
	//������ �迭�̰� ������ �κ��丮 ĭ���� �������� ������ �� �տ��ٰ� ����ִ´�
	while (m_nCount < 11)
	{
		if (Inventory[m_nCount] == ItemNum)
		{
			Inventory[m_nCount] += ItemCount;
			break;
		}
		else if (m_nCount == 10 && Inventory[m_nCount] != ItemNum)
		{
			m_nCount = 0;
			while (Inventory[m_nCount] != 0)
			{
				m_nCount++;
			}
			Inventory[m_nCount] == ItemNum;
		}
		m_nCount++;
	}
}

void cInventory::InventoryArrange()
{
	m_nCount = 1;

	while (m_nCount < 11)
	{
		while (Inventory[m_nCount - 1] == 0)
		{
			Inventory[m_nCount - 1] = Inventory[m_nCount];
			Inventory[m_nCount] = 0;
		}
	}
}