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
		cout << "{ 농장 관리인 }" << endl;
		cout << "주기적으로 빵을 만들어줄께" << endl;
		cout << "가끔씩 들어와서 빵 받아가" << endl << endl;

		cout << "{ 현재 가져갈 수 있는 빵의 양 }" << endl;

		while (m_nBreadCount >= 5)
		{
			m_nBreadCount -= 5;
			m_nBreadCost++;
		}

		cout << m_nBreadCost << "개" << endl << endl;
		cout << "{ 선택지 }" << endl;
		cout << "1. 빵 받기" << endl;
		cout << "2. 나가기" << endl;

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