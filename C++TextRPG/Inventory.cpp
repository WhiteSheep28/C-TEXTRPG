#include <iostream>

#include "MainSystem.h"
#include "Inventory.h"

cInventory::cInventory()
{
	memset(m_nInventorySlot, 0, 8 * sizeof(int));

	m_nBreadCode = 1;
	m_nHealingPotionCode = 2;

	m_nMyBread = 0;
	m_nMyHealingPotion = 0;
}

cInventory::~cInventory()
{

}

void cInventory::InventoryUi(cMainSystem* pMainSystem, cMainSystem* Character)
{
	while (1)
	{
		int nCount = 1;

		system("cls");
		cout << "{ �κ��丮 }" << endl;

		while (nCount != 8)
		{
			cout << nCount << ". ";

			switch (m_nInventorySlot[nCount])
			{
			case 1: 
				BreadUi();
				break;
			case 2: 
				HealthPotionUi();
				break;
			}

			cout << endl;

			nCount++;
		}

		cout << nCount << ". ������" << endl;

		pMainSystem->Setm_nSelect();

		switch (m_nInventorySlot[Getm_nSelect()])
		{
		case 1: 
			Character->Setm_nPlusHungry();
			m_nMyBread--;
			break;
		case 2: 
			Character->Setm_nPlusHealth();
			m_nMyHealingPotion--;
			break;
		default: continue;
		}
	}
}

void cInventory::BreadUi()
{
	cout << "�� " << m_nMyBread << "��";
}

void cInventory::HealthPotionUi()
{
	cout << "ü�� ���� " << m_nMyHealingPotion << "��";
}