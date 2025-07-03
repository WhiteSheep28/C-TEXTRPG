#include <iostream>

#include "MainSystem.h"
#include "FarmUi.h"

cFarmUi::cFarmUi()
{
	m_nBreadCount = 0;
	m_nBreadCost = 0;
}

cFarmUi::~cFarmUi()
{

}

void cFarmUi::FarmUi(cMainSystem* pMainSystem, cMainSystem* Character, cMainSystem* Inventory)
{
	while (1)
	{
		system("cls");
		cout << "{ ���� ������ }" << endl;
		cout << "�ֱ������� ���� ������ٲ�" << endl;
		cout << "������ ���ͼ� �� �޾ư�" << endl << endl;

		cout << "{ ���� ������ �� �ִ� ���� �� }" << endl;

		while (m_nBreadCount >= 5)
		{
			m_nBreadCount -= 5;
			m_nBreadCost++;
		}

		cout << m_nBreadCost << "��" << endl << endl;
		cout << "{ ������ }" << endl;
		cout << "1. �� �ޱ�" << endl;
		cout << "2. ������" << endl;

		pMainSystem->Setm_nSelect();

		switch (Getm_nSelect())
		{
		case 1:
		{
			Inventory->InputInventory(1, m_nBreadCost);

			m_nBreadCost = 0;

			break;
		}
		case 2: return;
		default: continue;
		}
	}
}