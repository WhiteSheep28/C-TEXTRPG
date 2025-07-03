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
		cout << "{ 인벤토리 }" << endl;

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

		cout << nCount << ". 나가기" << endl;

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

	//만약 인벤토리에 있을 때
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

	//만약 인벤토리에 없을 때
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

	//갯수가 다 떨어졌나 확인
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

	//배열의 맨 앞이 0인경우 뒤에 다른 숫자가 있나 확인
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
	cout << "빵 " << m_nMyBread << "개";
}

void cInventory::HealthPotionUi()
{
	cout << "체력 포션 " << m_nMyHealingPotion << "개";
}

