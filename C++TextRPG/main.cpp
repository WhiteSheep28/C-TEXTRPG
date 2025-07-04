#include <iostream>

#include "MainSystem.h"
#include "DungeonUi.h"
#include "Ui.h"
#include "FarmUi.h"
#include "Inventory.h"
#include "Warrior.h"
#include "Socerer.h"
#include "Archer.h"

using namespace std;

void main()
{
	cMainSystem* pMainSystem = new cMainSystem();
	cMainSystem* pUi = new cUi();

	//ó�� ����
	while (1)
	{
		pUi->StartMainUi();

		pMainSystem->Setm_nSelect();

		switch (pMainSystem->Getm_nSelect())
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			return;
		}
		default: continue;
		}
	}

	//ĳ���� ����â
	while (1)
	{
		pUi->CharacterSelectUi();

		pMainSystem->Setm_nSelect();

		switch (pMainSystem->Getm_nSelect())
		{
		case 1:
		{
			cMainSystem* pWarrior = new cWarrior;
			delete pWarrior;
			break;
		}
		case 2:
		{
			cMainSystem* pSocerer = new cSocerer;
			delete pSocerer;
			break;
		}
		case 3:
		{
			cMainSystem* pArcher = new cArcher;
			delete pArcher;
			break;
		}
		default: continue;
		}
	}


	
	delete pMainSystem;
	delete pUi;
}

//���� ������ �ֿ� �ҽ�����