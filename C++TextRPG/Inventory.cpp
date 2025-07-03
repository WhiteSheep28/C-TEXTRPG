#include <iostream>

#include "MainSystem.h"
#include "Inventory.h"

using namespace std;

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
		CleanInventory();

		int nCount = 0;
		
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

		switch (Getm_nSelect())
		{
		case 0:
		{
			if (m_nInventorySlot[Getm_nSelect()] == 1)
			{
				Character->Setm_nPlusHungry();
				m_nMyBread--;
			}
			if (m_nInventorySlot[Getm_nSelect()] == 2)
			{
				Character->Setm_nPlusHealth();
				m_nMyHealingPotion--;
			}
			break;
		}
		case 1:
		{
			if (m_nInventorySlot[Getm_nSelect()] == 1)
			{
				Character->Setm_nPlusHungry();
				m_nMyBread--;
			}
			if (m_nInventorySlot[Getm_nSelect()] == 2)
			{
				Character->Setm_nPlusHealth();
				m_nMyHealingPotion--;
			}
			break;
		}
		default: break;
		}

		if (Getm_nSelect() == nCount)
		{
			break;
		}
	}
}

void cInventory::InputInventory(int ItemCode, int ItemNum)
{
	int nCount = 0;

	//���� �κ��丮�� ���� ��
	while (nCount != 8)
	{
		if (m_nInventorySlot[nCount] == ItemCode)
		{

			if (ItemCode == 1)
			{
				m_nMyBread += ItemNum;
			}
			else if (ItemCode == 2)
			{
				m_nMyHealingPotion += ItemNum;
			}

			return;
		}
		nCount++;
	}

	//���� �κ��丮�� ���� ��
	if (nCount == 8)
	{
		nCount = 0;

		while (nCount != 8)
		{
			if (m_nInventorySlot[nCount] == 0)
			{
				m_nInventorySlot[nCount] = ItemCode;
				
				if (ItemCode == 1)
				{
					m_nMyBread += ItemNum;
					return;
				}
				else if (ItemCode == 2)
				{
					m_nMyHealingPotion += ItemNum;
					return;
				}
			}
			nCount++;
		}
	}
}

void cInventory::CleanInventory()
{
	int nCount = 0;
	int nCountPlus = 1;
	int nCountSecond = 0;

	//������ �� �������� Ȯ��
	while (nCount != 8)
	{
		while (m_nInventorySlot[nCount] != 0)
		{
			if (m_nInventorySlot[nCount] == 1)
			{
				if (m_nMyBread <= 0)
				{
					m_nInventorySlot[nCount] = 0;
				}

				break;
			}
			else if (m_nInventorySlot[nCount] == 2)
			{
				if (m_nMyHealingPotion <= 0)
				{
					m_nInventorySlot[nCount] = 0;
				}

				break;
			}
		}

		nCount++;
	}

	nCount = 0;

	//�迭�� �� ���� 0�ΰ�� �ڿ� �ٸ� ���ڰ� �ֳ� Ȯ��
	while (nCount != 8)
	{
		if (nCountSecond == 0 && m_nInventorySlot[nCount] == 0)
		{
			while (nCount != 8)
			{
				if (m_nInventorySlot[nCount] != 0)
				{
					while (m_nInventorySlot[0] == 0)
					{
						m_nInventorySlot[nCount - 1] = m_nInventorySlot[nCount];
						m_nInventorySlot[nCount] = 0;
					}
				}
				nCount++;
			}
			break;
		}
		nCount++;
	}

	nCountSecond = 1;
	nCount = nCountSecond + 1;

	while (nCountSecond != 8)
	{
		while (nCount != 8)
		{
			if (m_nInventorySlot[nCountSecond] == 0 && m_nInventorySlot[nCount] != 0)
			{
				while (m_nInventorySlot[nCountSecond] != 0)
				{
					m_nInventorySlot[nCount - 1] = m_nInventorySlot[nCount];
					m_nInventorySlot[nCount] = 0;

					nCount--;
				}
				nCount = nCountSecond + 1;
			}
			nCount++;
		}
		nCountSecond++;
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

